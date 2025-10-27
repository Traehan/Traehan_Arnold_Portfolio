#ifndef RW_LOG_H
#define RW_LOG_H

#include <stddef.h>     // size_t
#include <stdint.h>     // uint64_t
#include <sys/types.h>  // ssize_t
#include <time.h>       // struct timespec
#include <pthread.h>    // pthread_t

/* Max message length stored with each log entry */
#define RWLOG_MSG_MAX 128

/* One log record in the circular buffer (filled by the monitor). */
typedef struct {
    uint64_t        seq;                 /* global, monotonically increasing */
    pthread_t       tid;                 /* writer thread id */
    struct timespec ts;                  /* CLOCK_REALTIME timestamp */
    char            msg[RWLOG_MSG_MAX];  /* writer-supplied short message */
} rwlog_entry_t;

/* Monitor API */
int     rwlog_create(size_t capacity);
int     rwlog_destroy(void);

int     rwlog_begin_read(void);
ssize_t rwlog_snapshot(rwlog_entry_t *out, size_t max_entries);
int     rwlog_end_read(void);

int     rwlog_begin_write(void);
int     rwlog_append(const rwlog_entry_t *e);
int     rwlog_end_write(void);

/* Wake any threads blocked in the monitor (used on shutdown). Safe anytime. */
void    rwlog_wake_all(void);

#endif /* RW_LOG_H */
