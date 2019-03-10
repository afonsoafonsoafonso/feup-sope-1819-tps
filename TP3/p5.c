#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

int main() {
    int pid = fork(), status;

    if(pid > 0) {
        wait(&status);
        printf(" friends!\n");
    }
    else {
        int pid2 = fork(), status2;
        if(pid2 > 0) {
            wait(&status);
            printf(" my ");
        }
        else {
            printf("Hello ");
            exit(0);
        }
    }
    return 0;
}