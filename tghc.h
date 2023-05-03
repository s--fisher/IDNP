#include "tghc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

char *read_tghc_contents() {
    char *buffer = NULL;
    int fd = open(TGHC_FILE, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open %s: %s\n", TGHC_FILE, strerror(errno));
        return NULL;
    }
    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1) {
        fprintf(stderr, "Failed to seek %s: %s\n", TGHC_FILE, strerror(errno));
        close(fd);
        return NULL;
    }
    if (lseek(fd, 0, SEEK_SET) == -1) {
        fprintf(stderr, "Failed to seek %s: %s\n", TGHC_FILE, strerror(errno));
        close(fd);
        return NULL;
    }
    buffer = (char*) malloc(size + 1);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        close(fd);
        return NULL;
    }
    ssize_t bytes_read = read(fd, buffer, size);
    if (bytes_read == -1) {
        fprintf(stderr, "Failed to read %s: %s\n", TGHC_FILE, strerror(errno));
        free(buffer);
        close(fd);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return buffer;
}
