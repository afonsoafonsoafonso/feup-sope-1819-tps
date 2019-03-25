// PROGRAMA p3a.c 
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int sentido;

void sigusr_handler(int signo) {
        if(signo==SIGUSR1) sentido=1;
        else sentido=-1;
        return;
}

int main(void) {
    int v=0;
    sentido=1;
    srand(time(NULL));
    int r;
    pid_t pid;
    int status;

    struct sigaction action;
    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGUSR1,&action,NULL);
    sigaction(SIGUSR2,&action,NULL);

    pid = fork();


    if(pid==0) { //Codigo do filho 
        for(int i=0; i<50; i++) {
            sleep(1);
            v+=sentido;
            printf("v: %d\n",v);
        }
    }
    else { //Codigo do pai
        while(waitpid(pid,&status,WNOHANG)==0) {
            sleep(3);
            r = rand();
            if(r % 2 == 0) kill(pid,SIGUSR1);
            else kill(pid,SIGUSR2);
        }
    }

    return 0;
}

/*
int main(void) {
    int v=0;
    sentido=1;

    struct sigaction action;
    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGUSR1,&action,NULL);
    sigaction(SIGUSR2,&action,NULL);

    while(1) {
        sleep(1);
        v+=sentido;
        printf("v: %d\n",v);
    }

    return 0;
}
*/