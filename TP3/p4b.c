#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

int main(void){
    int pid, status;
    pid = fork();

    if(pid > 0){
        //printf("world!\n");
        printf("Hello ");
    }
    else
    {
        //printf("Hello ");
        printf("world!\n");
        exit(0);
    }
    return 0;
}