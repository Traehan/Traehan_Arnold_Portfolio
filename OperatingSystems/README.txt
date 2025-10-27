Traehan Arnold
Anthony Ilchev
CPSC380-01
Professor Tom Springer
10/17/2025

Runs in WSL Ubuntu or Linux

Files:

rw_log.h -> Header file defining the log entry structure and monitor API.  
rw_log.c -> Implementation of the writer-preference reader–writer monitor.  
rw_main.c -> Main driver that spawns reader/writer threads, collects metrics,
               and optionally dumps the circular log to CSV.

To Run:

 1. rm -f rw_log *.o
 2. gcc -Wall -Wextra -O2 -pthread -I. -o rw_log rw_main.c rw_log.c

This produces an executable named rw_log.

How to Use:

Run the program with optional command-line arguments:

    ./rw_log [options]

    Options:

    -c, --capacity <N>       Log capacity (default 1024)
    -r, --readers <N>        Number of reader threads (default 6)
    -w, --writers <N>        Number of writer threads (default 4)
    -b, --writer-batch <N>   Entries each writer appends per write (default 2)
    -s, --seconds <N>        Duration before timer stops program (default 10)
    -R, --rd-us <usec>       Microseconds a reader sleeps between reads
    -W, --wr-us <usec>       Microseconds a writer sleeps between writes
    -d, --dump               Dump the final log contents to log.csv
    -h, --help               Show help message

Signals:

Press Ctrl+C to stop early.
This safely wakes all waiting threads and writes results before exit.

Sample Output:

Example terminal output after running for 10 seconds:

    capacity=1024 readers=6 writers=4 batch=2 seconds=10 rd_us=2000 wr_us=3000 dump=1
    Wrote log.csv

    === Results ===
    Avg writer wait: 0.000 ms
    Avg reader critical-section time: 0.001 ms
    Reader monotonicity violations (observed): 3470399
    Throughput (approx, entries/sec): 102.40

A file named **log.csv** is also created containing all log entries: