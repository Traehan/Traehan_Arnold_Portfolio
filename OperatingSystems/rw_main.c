// rw_main.c
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <getopt.h>
#include "rw_log.h"  

// Config & Globals
struct config {
    int capacity;
    int readers;
    int writers;
    int writer_batch;
    int seconds;
    int rd_us;
    int wr_us;
    int dump_csv;
};

static volatile sig_atomic_t stop_flag = 0;

static void on_sigint(int signo) {
    (void)signo;
    stop_flag = 1;
    rwlog_wake_all(); // wake threads so they can exit cleanly
}

static void print_usage(const char *progname) {
    fprintf(stderr,
        "Usage: %s [options]\n"
        "Options:\n"
        "-c,  --capacity <N>        Log capacity (default 1024)\n"
        "-r,  --readers <N>         Number of reader threads (default 6)\n"
        "-w,  --writers <N>         Number of writer threads (default 4)\n"
        "-b,  --writer-batch <N>    Entries written per writer section (default 2)\n"
        "-s,  --seconds <N>         Total run time (default 10)\n"
        "-R,  --rd-us <usec>        Reader sleep between ops (default 2000)\n"
        "-W,  --wr-us <usec>        Writer sleep between ops (default 3000)\n"
        "-d,  --dump                Dump final log to log.csv\n"
        "-h,  --help                Show this help message\n",
        progname);
}

static void parse_args(int argc, char **argv, struct config *cfg) {
    // defaults
    cfg->capacity     = 1024;
    cfg->readers      = 6;
    cfg->writers      = 4;
    cfg->writer_batch = 2;
    cfg->seconds      = 10;
    cfg->rd_us        = 2000;
    cfg->wr_us        = 3000;
    cfg->dump_csv     = 0;

    static struct option long_opts[] = {
        {"capacity",     required_argument, 0, 'c'},
        {"readers",      required_argument, 0, 'r'},
        {"writers",      required_argument, 0, 'w'},
        {"writer-batch", required_argument, 0, 'b'},
        {"seconds",      required_argument, 0, 's'},
        {"rd-us",        required_argument, 0, 'R'},
        {"wr-us",        required_argument, 0, 'W'},
        {"dump",         no_argument,       0, 'd'},
        {"help",         no_argument,       0, 'h'},
        {0,0,0,0}
    };

    int c;
    while ((c = getopt_long(argc, argv, "c:r:w:b:s:R:W:dh", long_opts, NULL)) != -1) {
        switch (c) {
            case 'c': cfg->capacity = atoi(optarg); break;
            case 'r': cfg->readers = atoi(optarg); break;
            case 'w': cfg->writers = atoi(optarg); break;
            case 'b': cfg->writer_batch = atoi(optarg); break;
            case 's': cfg->seconds = atoi(optarg); break;
            case 'R': cfg->rd_us = atoi(optarg); break;
            case 'W': cfg->wr_us = atoi(optarg); break;
            case 'd': cfg->dump_csv = 1; break;
            case 'h':
            default:
                print_usage(argv[0]);
                exit(c == 'h' ? 0 : 1);
        }
    }

    if (cfg->capacity <= 0 || cfg->readers < 0 || cfg->writers < 0 ||
        cfg->writer_batch <= 0 || cfg->seconds <= 0 ||
        cfg->rd_us < 0 || cfg->wr_us < 0) {
        fprintf(stderr, "Invalid arguments.\n");
        print_usage(argv[0]);
        exit(1);
    }
}

// Timing helpers 
static inline long long nsec_since(const struct timespec *start, clockid_t clk) {
    struct timespec now;
    clock_gettime(clk, &now);
    long long sec  = (long long)now.tv_sec  - (long long)start->tv_sec;
    long long nsec = (long long)now.tv_nsec - (long long)start->tv_nsec;
    return sec*1000000000LL + nsec;
}

// Metrics 
typedef struct {
    // writer: time waiting to enter write section
    uint64_t wait_ns_sum;
    uint64_t wait_count;

    // reader: time inside read section
    uint64_t crit_ns_sum;
    uint64_t crit_count;

    // monotonicity checks (readers)
    uint64_t last_seq_seen;
    uint64_t monotonic_violations;
} thread_metrics_t;

//  Writer thread 
typedef struct {
    int id;
    int batch;
    int sleep_us;
    thread_metrics_t m;
} writer_arg_t;

static void* writer_main(void *argp) {
    writer_arg_t *arg = (writer_arg_t*)argp;
    int local_counter = 0;

    while (!stop_flag) {
        struct timespec t0;
        clock_gettime(CLOCK_MONOTONIC, &t0);

        if (rwlog_begin_write() != 0) break;

        long long waited_ns = nsec_since(&t0, CLOCK_MONOTONIC);
        arg->m.wait_ns_sum += (waited_ns > 0 ? (uint64_t)waited_ns : 0);
        arg->m.wait_count++;

        //Append batch entries
        for (int i = 0; i < arg->batch; i++) {
            rwlog_entry_t e;
            memset(&e, 0, sizeof(e));
            //Fill only msg, monitor fills seq/tid/ts
            //"writer3-msg17"
            char msg[RWLOG_MSG_MAX];
            snprintf(msg, sizeof(msg), "writer%d-msg%d", arg->id, local_counter++);
            strncpy(e.msg, msg, RWLOG_MSG_MAX - 1);
            e.msg[RWLOG_MSG_MAX - 1] = '\0';

            if (rwlog_append(&e) != 0) {
                // If append fails, try to end write and exit
                break;
            }
        }

        rwlog_end_write();

        if (arg->sleep_us > 0) usleep(arg->sleep_us);
    }
    return NULL;
}

//Reader thread
typedef struct {
    int id;
    int sleep_us;
    thread_metrics_t m;
} reader_arg_t;

static void* reader_main(void *argp) {
    reader_arg_t *arg = (reader_arg_t*)argp;
    // local snapshot buffer
    const size_t SNAP_MAX = 128;
    rwlog_entry_t *buf = (rwlog_entry_t*)malloc(sizeof(rwlog_entry_t)*SNAP_MAX);
    if (!buf) return NULL;

    while (!stop_flag) {
        struct timespec t_enter;
        clock_gettime(CLOCK_MONOTONIC, &t_enter);

        if (rwlog_begin_read() != 0) break;

        // inside read section: snapshot
        ssize_t n = rwlog_snapshot(buf, SNAP_MAX);

        struct timespec t_leave;
        clock_gettime(CLOCK_MONOTONIC, &t_leave);

        rwlog_end_read();

        // measure critical section time
        long long ns = (t_leave.tv_sec - t_enter.tv_sec)*1000000000LL +
                       (t_leave.tv_nsec - t_enter.tv_nsec);
        if (ns > 0) {
            arg->m.crit_ns_sum += (uint64_t)ns;
            arg->m.crit_count++;
        }

        // simple monotonicity check on sequences
        if (n > 0) {
            // buf[0..n-1] in chronological order
            for (ssize_t i = 0; i < n; i++) {
            uint64_t s = buf[i].seq;
            if (s < arg->m.last_seq_seen) {
                arg->m.monotonic_violations++;
            }
        if (s > arg->m.last_seq_seen) arg->m.last_seq_seen = s;
    }
        }

        if (arg->sleep_us > 0) usleep(arg->sleep_us);
    }

    free(buf);
    return NULL;
}

//Timer thread 
typedef struct {
    int seconds;
} timer_arg_t;

static void* timer_main(void *argp) {
    timer_arg_t *a = (timer_arg_t*)argp;
    for (int i = 0; i < a->seconds && !stop_flag; i++) {
        sleep(1);
    }
    stop_flag = 1;
    rwlog_wake_all();
    return NULL;
}

// CSV dump 
static int dump_csv_file(const char *path, size_t cap) {
    FILE *f = fopen(path, "w");
    if (!f) {
        fprintf(stderr, "Failed to open %s: %s\n", path, strerror(errno));
        return -1;
    }
    // snapshot final log
    rwlog_entry_t *buf = (rwlog_entry_t*)malloc(sizeof(rwlog_entry_t)*cap);
    if (!buf) { fclose(f); return -1; }

    if (rwlog_begin_read() != 0) { free(buf); fclose(f); return -1; }
    ssize_t n = rwlog_snapshot(buf, cap);
    rwlog_end_read();

    fprintf(f, "seq,tid,timestamp_sec,timestamp_nsec,msg\n");
    for (ssize_t i = 0; i < n; i++) {
        fprintf(f, "%llu,%llu,%ld,%ld,%s\n",
            (unsigned long long)buf[i].seq,
            (unsigned long long)buf[i].tid,
            (long)buf[i].ts.tv_sec,
            (long)buf[i].ts.tv_nsec,
            buf[i].msg);
    }

    free(buf);
    fclose(f);
    return 0;
}

// Main
int main(int argc, char **argv) {
    struct config cfg;
    parse_args(argc, argv, &cfg);

    printf("capacity=%d readers=%d writers=%d batch=%d seconds=%d rd_us=%d wr_us=%d dump=%d\n",
           cfg.capacity, cfg.readers, cfg.writers, cfg.writer_batch,
           cfg.seconds, cfg.rd_us, cfg.wr_us, cfg.dump_csv);

    // Create monitor
    if (rwlog_create((size_t)cfg.capacity) != 0) {
        fprintf(stderr, "rwlog_create failed: %s\n", strerror(errno));
        return 1;
    }

    // SIGINT handler
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_sigint;
    sigaction(SIGINT, &sa, NULL);

    // Start timer thread
    pthread_t timer_th;
    timer_arg_t targs = {.seconds = cfg.seconds};
    if (pthread_create(&timer_th, NULL, timer_main, &targs) != 0) {
        fprintf(stderr, "pthread_create(timer) failed\n");
        rwlog_destroy();
        return 1;
    }

    // Create writers
    pthread_t *wth = NULL;
    writer_arg_t *warg = NULL;
    if (cfg.writers > 0) {
        wth  = (pthread_t*)calloc(cfg.writers, sizeof(pthread_t));
        warg = (writer_arg_t*)calloc(cfg.writers, sizeof(writer_arg_t));
        if (!wth || !warg) { fprintf(stderr, "OOM writers\n"); stop_flag=1; rwlog_wake_all(); }

        for (int i = 0; i < cfg.writers && !stop_flag; i++) {
            warg[i].id = i;
            warg[i].batch = cfg.writer_batch;
            warg[i].sleep_us = cfg.wr_us;
            memset(&warg[i].m, 0, sizeof(warg[i].m));
            if (pthread_create(&wth[i], NULL, writer_main, &warg[i]) != 0) {
                fprintf(stderr, "pthread_create(writer %d) failed\n", i);
                stop_flag = 1; rwlog_wake_all();
                break;
            }
        }
    }

    // Create readers
    pthread_t *rth = NULL;
    reader_arg_t *rarg = NULL;
    if (cfg.readers > 0) {
        rth  = (pthread_t*)calloc(cfg.readers, sizeof(pthread_t));
        rarg = (reader_arg_t*)calloc(cfg.readers, sizeof(reader_arg_t));
        if (!rth || !rarg) { fprintf(stderr, "OOM readers\n"); stop_flag=1; rwlog_wake_all(); }

        for (int i = 0; i < cfg.readers && !stop_flag; i++) {
            rarg[i].id = i;
            rarg[i].sleep_us = cfg.rd_us;
            memset(&rarg[i].m, 0, sizeof(rarg[i].m));
            if (pthread_create(&rth[i], NULL, reader_main, &rarg[i]) != 0) {
                fprintf(stderr, "pthread_create(reader %d) failed\n", i);
                stop_flag = 1; rwlog_wake_all();
                break;
            }
        }
    }

    // Join workers
    if (wth) {
        for (int i = 0; i < cfg.writers; i++) {
            if (wth[i]) pthread_join(wth[i], NULL);
        }
    }
    if (rth) {
        for (int i = 0; i < cfg.readers; i++) {
            if (rth[i]) pthread_join(rth[i], NULL);
        }
    }

    // Join timer
    pthread_join(timer_th, NULL);

    // Optional CSV dump
    if (cfg.dump_csv) {
        if (dump_csv_file("log.csv", (size_t)cfg.capacity) == 0) {
            printf("Wrote log.csv\n");
        }
    }

    // Compute & print metrics
    // writers: average wait to enter write section
    uint64_t w_wait_ns_sum = 0, w_wait_cnt = 0;
    if (warg) {
        for (int i = 0; i < cfg.writers; i++) {
            w_wait_ns_sum += warg[i].m.wait_ns_sum;
            w_wait_cnt    += warg[i].m.wait_count;
        }
    }

    // readers: average time inside read section
    uint64_t r_crit_ns_sum = 0, r_crit_cnt = 0;
    uint64_t r_monovios = 0;
    if (rarg) {
        for (int i = 0; i < cfg.readers; i++) {
            r_crit_ns_sum += rarg[i].m.crit_ns_sum;
            r_crit_cnt    += rarg[i].m.crit_count;
            r_monovios    += rarg[i].m.monotonic_violations;
        }
    }

    double avg_writer_ms = (w_wait_cnt ? ((double)w_wait_ns_sum / 1e6) / (double)w_wait_cnt : 0.0);
    double avg_reader_ms = (r_crit_cnt ? ((double)r_crit_ns_sum / 1e6) / (double)r_crit_cnt : 0.0);

    // throughput: take a final snapshot count and divide by seconds
    size_t snap_cap = (size_t)cfg.capacity;
    rwlog_entry_t *final = (rwlog_entry_t*)malloc(sizeof(rwlog_entry_t)*snap_cap);
    ssize_t final_n = 0;
    if (final) {
        if (rwlog_begin_read() == 0) {
            final_n = rwlog_snapshot(final, snap_cap);
            rwlog_end_read();
        }
    }
    double throughput = (cfg.seconds > 0 && final_n > 0) ? ((double)final_n / (double)cfg.seconds) : 0.0;

    printf("\n=== Results ===\n");
    printf("Avg writer wait: %.3f ms\n", avg_writer_ms);
    printf("Avg reader critical-section time: %.3f ms\n", avg_reader_ms);
    printf("Reader monotonicity violations (observed): %llu\n", (unsigned long long)r_monovios);
    printf("Throughput (approx, entries/sec): %.2f\n", throughput);

    free(final);
    free(wth); free(warg);
    free(rth); free(rarg);

    rwlog_destroy();
    return 0;
}
