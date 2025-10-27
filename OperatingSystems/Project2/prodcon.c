// prodcon.c
// POSIX threads + mutex + counting semaphores solution to bounded buffer
// Usage: ./prodcon <delay_seconds> <num_producers> <num_consumers>

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sched.h>
#include <string.h>
#include <errno.h>

typedef struct {
    uint8_t  data[30];
    uint16_t cksum;
} buffer_item;

#define BUFFER_SIZE 10

// ----- Shared buffer state -----
static buffer_item buffer[BUFFER_SIZE];
static int in_idx  = 0;   // next insertion position
static int out_idx = 0;   // next removal position

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static sem_t empty_sem; // counts empty slots
static sem_t full_sem;  // counts full slots

// ----- Helpers -----
static uint16_t compute_checksum(const uint8_t *data, size_t n) {
    uint32_t sum = 0;
    for (size_t i = 0; i < n; ++i) sum += data[i];
    return (uint16_t)(sum & 0xFFFFu);
}

static void generate_item(buffer_item *it, unsigned int *seed) {
    for (size_t i = 0; i < sizeof(it->data); ++i) {
        // rand_r is thread-safe; falls back to rand() if not available
        #ifdef __GLIBC__
        it->data[i] = (uint8_t)(rand_r(seed) & 0xFF);
        #else
        it->data[i] = (uint8_t)(rand() & 0xFF);
        #endif
    }
    it->cksum = compute_checksum(it->data, sizeof(it->data));
}

// Cleanup handler to ensure mutex is unlocked if a thread is cancelled mid-critical section
static void cleanup_mutex_unlock(void *arg) {
    pthread_mutex_t *m = (pthread_mutex_t *)arg;
    pthread_mutex_unlock(m);
}

// ----- Buffer ops -----
static int insert_item(const buffer_item *item) {
    // Wait for an empty slot (cancellation point)
    if (sem_wait(&empty_sem) != 0) return -1;

    pthread_cleanup_push(cleanup_mutex_unlock, &mutex);
    pthread_mutex_lock(&mutex);

    buffer[in_idx] = *item;
    in_idx = (in_idx + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    pthread_cleanup_pop(0);

    // Mark a slot as full
    if (sem_post(&full_sem) != 0) return -1;
    return 0;
}

static int remove_item(buffer_item *item_out) {
    // Wait for an available item (cancellation point)
    if (sem_wait(&full_sem) != 0) return -1;

    pthread_cleanup_push(cleanup_mutex_unlock, &mutex);
    pthread_mutex_lock(&mutex);

    *item_out = buffer[out_idx];
    out_idx = (out_idx + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mutex);
    pthread_cleanup_pop(0);

    // Mark a slot as empty
    if (sem_post(&empty_sem) != 0) return -1;
    return 0;
}

// ----- Threads -----
static void *producer(void *param) {
    unsigned int seed =
        (unsigned int)time(NULL) ^ (unsigned int)(uintptr_t)pthread_self();

    for (;;) {
        // yield ~40% chance to simulate preemption
        #ifdef __GLIBC__
        if ((rand_r(&seed) % 100) < 40) sched_yield();
        #else
        if ((rand() % 100) < 40) sched_yield();
        #endif

        pthread_testcancel(); // explicit cancellation point

        buffer_item item;
        generate_item(&item, &seed);

        if (insert_item(&item) != 0) {
            fprintf(stderr, "[producer] insert_item error: %s\n", strerror(errno));
        }
    }
    return NULL;
}

static void *consumer(void *param) {
    unsigned int seed =
        (unsigned int)time(NULL) ^ (unsigned int)(uintptr_t)pthread_self();

    (void)seed; // not needed here, but kept for symmetry

    for (;;) {
        // yield ~40% chance to simulate preemption
        #ifdef __GLIBC__
        if ((rand_r(&seed) % 100) < 40) sched_yield();
        #else
        if ((rand() % 100) < 40) sched_yield();
        #endif

        pthread_testcancel(); // explicit cancellation point

        buffer_item item;
        if (remove_item(&item) != 0) {
            fprintf(stderr, "[consumer] remove_item error: %s\n", strerror(errno));
            continue;
        }

        // Verify checksum
        uint16_t calc = compute_checksum(item.data, sizeof(item.data));
        if (calc != item.cksum) {
            fprintf(stderr,
                    "[consumer] CHECKSUM MISMATCH! expected=0x%04X calculated=0x%04X\n",
                    item.cksum, calc);
            // Exit entire process on data corruption (per spec)
            // Note: In a larger app, you might signal others then exit.
            _exit(EXIT_FAILURE);
        }

        // (Optional) do some light work to simulate processing
        // usleep(1000);
    }
    return NULL;
}

// ----- Main -----
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <delay_seconds> <num_producers> <num_consumers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int delay = atoi(argv[1]);
    int nprod = atoi(argv[2]);
    int ncons = atoi(argv[3]);
    if (delay < 0 || nprod <= 0 || ncons <= 0) {
        fprintf(stderr, "Invalid arguments. delay>=0, producers>0, consumers>0.\n");
        return EXIT_FAILURE;
    }

    // Seed PRNG (each thread also seeds)
    srand((unsigned int)(time(NULL) ^ getpid()));

    // Init semaphores
    if (sem_init(&empty_sem, 0, BUFFER_SIZE) != 0) {
        perror("sem_init(empty_sem)");
        return EXIT_FAILURE;
    }
    if (sem_init(&full_sem, 0, 0) != 0) {
        perror("sem_init(full_sem)");
        sem_destroy(&empty_sem);
        return EXIT_FAILURE;
    }

    // Create threads
    pthread_t *prod_threads = calloc((size_t)nprod, sizeof(pthread_t));
    pthread_t *cons_threads = calloc((size_t)ncons, sizeof(pthread_t));
    if (!prod_threads || !cons_threads) {
        fprintf(stderr, "Allocation failure.\n");
        sem_destroy(&empty_sem);
        sem_destroy(&full_sem);
        free(prod_threads); free(cons_threads);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < nprod; ++i) {
        int rc = pthread_create(&prod_threads[i], NULL, producer, NULL);
        if (rc != 0) {
            fprintf(stderr, "pthread_create(producer %d) failed: %s\n", i, strerror(rc));
        }
    }
    for (int i = 0; i < ncons; ++i) {
        int rc = pthread_create(&cons_threads[i], NULL, consumer, NULL);
        if (rc != 0) {
            fprintf(stderr, "pthread_create(consumer %d) failed: %s\n", i, strerror(rc));
        }
    }

    // Sleep then cancel everyone (threads are infinite loops)
    sleep((unsigned int)delay);

    for (int i = 0; i < nprod; ++i) pthread_cancel(prod_threads[i]);
    for (int i = 0; i < ncons; ++i) pthread_cancel(cons_threads[i]);

    // Join to ensure clean termination
    for (int i = 0; i < nprod; ++i) {
        if (prod_threads[i]) pthread_join(prod_threads[i], NULL);
    }
    for (int i = 0; i < ncons; ++i) {
        if (cons_threads[i]) pthread_join(cons_threads[i], NULL);
    }

    // Cleanup
    sem_destroy(&empty_sem);
    sem_destroy(&full_sem);
    pthread_mutex_destroy(&mutex);
    free(prod_threads);
    free(cons_threads);

    return EXIT_SUCCESS;
}
