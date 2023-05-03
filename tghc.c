#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 512

struct message {
    long type;
    int data;
};

void handle_message(struct message msg) {
    switch(msg.data) {
        case -1:
            printf("CALL\n");
            break;
        case 0:
            printf("WAITS\n");
            break;
        case 1:
            printf("WAIT CALLS\n");
            break;
        default:
            printf("Unknown message received\n");
            break;
    }
}

int main() {
    key_t key = ftok("/TGHC(A)", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct message msg;
    while (1) {
        if (msgrcv(msgid, &msg, sizeof(msg.data), 0, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        handle_message(msg);
    }

    return EXIT_SUCCESS;
}
