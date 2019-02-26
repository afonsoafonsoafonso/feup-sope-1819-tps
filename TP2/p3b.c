#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/times.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv) {
    unsigned char buffer[BUFFER_SIZE];
    int s = open(argv[1], O_RDONLY), r;
    int nr;

    if(argc==3) {
        r = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        printf("%d\n",r);
        dup2(r,STDOUT_FILENO);
        close(r);
    }

    while((nr=read(s,buffer,BUFFER_SIZE))>0) {
        write(STDOUT_FILENO,buffer,nr);
    }

    close(s);

    return 0;
}