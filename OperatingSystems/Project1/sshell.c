#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 80  // maximum input length (per assignment)

int main(void) {
    char line[MAX_LINE];                    // raw input buffer
    char *args[MAX_LINE/2 + 1];             // tokens for execvp (NULL-terminated)
    int should_run = 1;                     // exit flag

    while (should_run) {
        // prompt
        printf("osh> ");
        fflush(stdout);

        // read a line (handle Ctrl-D / EOF)
        if (fgets(line, sizeof(line), stdin) == NULL) {
            putchar('\n');
            break;
        }

        // tokenize input
        int argc = 0;
        char *tok = strtok(line, " \t\n");
        if (!tok) continue;                 // blank line

        // collect tokens into args
        while (tok && argc < (int)(MAX_LINE/2)) {
            args[argc++] = tok;
            tok = strtok(NULL, " \t\n");
        }
        if (argc == 0) continue;

        // built-in: exit
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        // background?
        int background = 0;
        if (strcmp(args[argc - 1], "&") == 0) {
            background = 1;
            args[--argc] = NULL;            // drop the "&"
        } else {
            args[argc] = NULL;              // NULL-terminate for execvp
        }

        // fork and exec
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        }
        if (pid == 0) {
            // child
            execvp(args[0], args);
            perror("execvp");               // only reached on error
            _exit(1);
        } else {
            // parent
            if (!background) {
                (void)waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}
