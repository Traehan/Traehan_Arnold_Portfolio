#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include "rw_log.h" 

// Internal monitor state
typedef struct {
    // synchronization
    pthread_mutex_t mtx;
    pthread_cond_t  can_read;
    pthread_cond_t  can_write;

    // RW state
    size_t readers_active;      // number of readers inside
    size_t writers_waiting;     // writers queued
    int    writer_active;       // 0/1

    // circular log
    rwlog_entry_t *buf;
    size_t capacity;
    size_t len;                 // number of valid entries (<= capacity)
    size_t head;                // index of next write position
    uint64_t seq_next;          // next global sequence to assign
} rwlog_monitor_t;

static rwlog_monitor_t *G = NULL;

static int timespec_diff_ns(const struct timespec *a, const struct timespec *b, long long *ns_out) {
    // ns = a - b
    long long sec = (long long)a->tv_sec - (long long)b->tv_sec;
    long long nsec = (long long)a->tv_nsec - (long long)b->tv_nsec;
    long long tot = sec*1000000000LL + nsec;
    *ns_out = tot;
    return 0;
}

//API 

int rwlog_create(size_t capacity) {
    if (G) return 0; // already created
    if (capacity == 0) { errno = EINVAL; return -1; }

    rwlog_monitor_t *m = (rwlog_monitor_t*)calloc(1, sizeof(*m));
    if (!m) return -1;

    m->buf = (rwlog_entry_t*)calloc(capacity, sizeof(rwlog_entry_t));
    if (!m->buf) { free(m); return -1; }

    m->capacity = capacity;
    m->len = 0;
    m->head = 0;
    m->seq_next = 1;

    if (pthread_mutex_init(&m->mtx, NULL) != 0) { free(m->buf); free(m); return -1; }
    if (pthread_cond_init(&m->can_read, NULL) != 0) { pthread_mutex_destroy(&m->mtx); free(m->buf); free(m); return -1; }
    if (pthread_cond_init(&m->can_write, NULL) != 0) {
        pthread_cond_destroy(&m->can_read);
        pthread_mutex_destroy(&m->mtx);
        free(m->buf); free(m);
        return -1;
    }

    G = m;
    return 0;
}

int rwlog_destroy(void) {
    if (!G) return 0;
    pthread_mutex_lock(&G->mtx);
    pthread_mutex_unlock(&G->mtx);

    pthread_cond_destroy(&G->can_read);
    pthread_cond_destroy(&G->can_write);
    pthread_mutex_destroy(&G->mtx);

    free(G->buf);
    free(G);
    G = NULL;
    return 0;
}

int rwlog_begin_read(void) {
    if (!G) { errno = EINVAL; return -1; }
    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    // Writer preference: block readers if writer active OR writers waiting.
    while (G->writer_active || G->writers_waiting > 0) {
        int rc = pthread_cond_wait(&G->can_read, &G->mtx);
        if (rc != 0) { pthread_mutex_unlock(&G->mtx); errno = rc; return -1; }
    }
    G->readers_active++;

    return pthread_mutex_unlock(&G->mtx);
}

ssize_t rwlog_snapshot(rwlog_entry_t *out, size_t max_entries) {
    if (!G || !out || max_entries == 0) { errno = EINVAL; return -1; }

    //assume caller is inside the read section already.
    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    // Copy newest <= max_entries
    size_t want = (G->len < max_entries) ? G->len : max_entries;

    
    for (size_t i = 0; i < want; i++) {
        // newest is head-1, then head-2, ...
        size_t idx = (G->head + G->capacity - 1 - i) % G->capacity;
        out[want - 1 - i] = G->buf[idx]; // place in oldest to newest
    }

    pthread_mutex_unlock(&G->mtx);
    return (ssize_t)want;
}

int rwlog_end_read(void) {
    if (!G) { errno = EINVAL; return -1; }
    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    if (G->readers_active == 0) {
        pthread_mutex_unlock(&G->mtx);
        errno = EPERM;
        return -1;
    }
    G->readers_active--;

    // If last reader leaves and writers are waiting, wake one writer.
    if (G->readers_active == 0 && G->writers_waiting > 0) {
        pthread_cond_signal(&G->can_write);
    }

    return pthread_mutex_unlock(&G->mtx);
}

int rwlog_begin_write(void) {
    if (!G) { errno = EINVAL; return -1; }
    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    G->writers_waiting++;
    while (G->writer_active || G->readers_active > 0) {
        int rc = pthread_cond_wait(&G->can_write, &G->mtx);
        if (rc != 0) {
            G->writers_waiting--;
            pthread_mutex_unlock(&G->mtx);
            errno = rc;
            return -1;
        }
    }
    G->writers_waiting--;
    G->writer_active = 1;

    return pthread_mutex_unlock(&G->mtx);
}

int rwlog_append(const rwlog_entry_t *e) {
    if (!G || !e) { errno = EINVAL; return -1; }

    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    if (!G->writer_active) {
        pthread_mutex_unlock(&G->mtx);
        errno = EPERM;
        return -1; // must be inside write section
    }

    // Fill the record
    rwlog_entry_t rec;
    memset(&rec, 0, sizeof(rec));
    rec.seq = G->seq_next++;
    rec.tid = pthread_self();
    clock_gettime(CLOCK_REALTIME, &rec.ts);
    // copy message
    strncpy(rec.msg, e->msg, RWLOG_MSG_MAX - 1);
    rec.msg[RWLOG_MSG_MAX - 1] = '\0';

    // write into circular buffer at head
    G->buf[G->head] = rec;
    G->head = (G->head + 1) % G->capacity;
    if (G->len < G->capacity) G->len++;

    pthread_mutex_unlock(&G->mtx);
    return 0;
}

int rwlog_end_write(void) {
    if (!G) { errno = EINVAL; return -1; }
    if (pthread_mutex_lock(&G->mtx) != 0) return -1;

    if (!G->writer_active) {
        pthread_mutex_unlock(&G->mtx);
        errno = EPERM;
        return -1;
    }
    G->writer_active = 0;

    // On writer exit: if writers are waiting → signal one writer; else broadcast readers
    if (G->writers_waiting > 0) {
        pthread_cond_signal(&G->can_write);
    } else {
        pthread_cond_broadcast(&G->can_read);
    }

    return pthread_mutex_unlock(&G->mtx);
}

void rwlog_wake_all(void) {
    if (!G) return;
    pthread_mutex_lock(&G->mtx);
    pthread_cond_broadcast(&G->can_write);
    pthread_cond_broadcast(&G->can_read);
    pthread_mutex_unlock(&G->mtx);
}
