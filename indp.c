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

void execute(char **args) {
    pid_t pid, wpid;
    int status;
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
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void smash() {
    char *line;
    char **args;
    int status;
    do {
        printf("trundle ? > ");
        line = read_line();
        args = parse_args(line);
        execute(args);
        free(line);
        free(args);
    } while (status);
}

int main() {
    smash();
    return EXIT_SUCCESS;
}
