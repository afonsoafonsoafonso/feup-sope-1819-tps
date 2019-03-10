#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
    //write(STDOUT_FILENO,"1",1);
    printf("1\n");
    if(fork() > 0) {
        printf("2");
        printf("3");
        //write(STDERR_FILENO,"2",1);
        //write(STDOUT_FILENO,"3",1);
    }
    else {
        printf("4");
        printf("5");
        //write(STDOUT_FILENO,"4",1);
        //write(STDOUT_FILENO,"5",1);
    }
    //write(STDOUT_FILENO,"\n",1);
    printf("\n");
}