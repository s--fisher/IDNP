#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

enum ProcessStatus {
    CALL,
    WAITS,
    WAIT_CALLS
};

char *read_line() {
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

char **parse_args(char *line) {
    int bufsize = 64, pos = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    token = strtok(line, " \t\n");
    while (token != NULL) {
        tokens[pos] = token;
        pos++;
        if (pos >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }
        token = strtok(NULL, " \t\n");
    }
    tokens[pos] = NULL;
    return tokens;
}

void execute(char **args, enum ProcessStatus *status) {
    pid_t pid, wpid;
    int proc_status;
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("idnp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("idnp");
    } else {
        do {
            wpid = waitpid(pid, &proc_status, WUNTRACED);
        } while (!WIFEXITED(proc_status) && !WIFSIGNALED(proc_status));
        if (wpid == -1) {
            *status = CALL;
        } else if (WIFEXITED(proc_status)) {
            *status = WAITS;
        } else {
            *status = WAIT_CALLS;
        }
    }
}

void run() {
    char *line;
    char **args;
    enum ProcessStatus status;
    do {
        printf("trundle ? > ");
        line = read_line();
        args = parse_args(line);
        execute(args, &status);
        free(line);
        free(args);

        switch (status) {
            case CALL:
                printf("CALL\n");
                break;
            case WAITS:
                printf("WAITS\n");
                break;
            case WAIT_CALLS:
                printf("WAIT CALLS\n");
                break;
        }
    } while (status != WAITS);
}

int main() {
    run();
    return EXIT_SUCCESS;
} 