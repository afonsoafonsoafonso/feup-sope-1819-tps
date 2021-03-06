// PROGRAMA p01a.c 
#define _POSIX_C_SOURCE 200809L

#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

void sigint_handler(int signo) {   
    printf("In SIGINT handler ...\n"); 
} 

int main(void) {   
    if (signal(SIGINT,sigint_handler) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);   
    }   
        
    printf("Sleeping for 30 seconds ...\n");   

    printf("Sleeping for 30 seconds ...\n");
    int sleep_return = sleep(30);
    
    while (sleep_return != 0) {
        sleep_return = sleep(sleep_return);
}

    printf("Waking up ...\n");   
    exit(0); 
}