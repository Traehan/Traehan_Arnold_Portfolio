#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]){

    int option;
    int verbose_flag = 0;

    //define log options
    static struct option long_options[] = {

    {"help", no_argument,           0,  'h'},
    {"version", no_argument,        0,  'v'},
    {"output", required_argument,   0,  'o'},
    {"help", no_argument,           0,  'h'},
    {0,0,0,0}
    };


while ((option = getopt_long(argc, argv, "hvo:", long_options, NULL)) != -1){
    switch (option) {
        case 'h':
            printf("usage: %s [--help] [--version] [--output <file>] [--verbose] \n", argv[0]);
            break;
        case 'v':
            printf("Version 1.0\n");
            break;
        case 'o':
            printf("Output file: %s\n", optarg);
            break;
        case 0:
            if (verbose_flag)
                printf("Verbose mode enabled\n");
            break;
        case '?':
        //getopt_long already printed a message error
            break;
        default:
            abort ();
    }
}

return 0;
}
