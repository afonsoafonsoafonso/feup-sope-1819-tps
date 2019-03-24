// PROGRAMA p3a.c 
#define _POSIX_C_SOURCE 200809L

#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>

int sentido;

void sigusr_handler(int signo) {
        if(signo==SIGUSR1) sentido=1;
        else sentido=-1;
        return;
}

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