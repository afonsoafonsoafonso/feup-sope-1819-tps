#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_handler(int signo) {
    wait(NULL);
    printf("Child ended within time limit\n");
    exit(0);
}

int main(int argc, char **argv) {
    int time_limit = atoi(argv[1]);
    pid_t pid;

    pid=fork();

    if(pid==0) {
        execl(argv[2], argv[2], argv[3], NULL);
        printf("Error executing %s\n",argv[2]);
        exit(1);
    }
    else {
        struct sigaction action;
        action.sa_handler = child_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags=0;
        sigaction(SIGCHLD,&action,NULL); 

        sleep(5);

        action.sa_handler = SIG_DFL;
        sigemptyset(&action.sa_mask);
        action.sa_flags=0;
        sigaction(SIGCHLD,&action,NULL);
        printf("Child failed to end within time limit\n");
        kill(pid,9);
        wait(NULL);
        exit(1);
    }
    return 0;
}