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
    //srand(time(NULL));
    unsigned char buffer[BUFFER_SIZE];
    int s = open(argv[1], O_RDONLY);
    //int r = open(argv[2], O_WRONLY | O_TRUNC);
    int nr;

    while((nr=read(s,buffer,BUFFER_SIZE))>0) {
        write(STDOUT_FILENO,buffer,nr);
    }

    /*struct tms *tempos = malloc(sizeof(struct tms));
    times(tempos);
    printf("utime: %.50f\n",(float)tempos->tms_utime/sysconf(_SC_CLK_TCK));
    printf("stime: %.50f\n\n",(float)tempos->tms_stime/sysconf(_SC_CLK_TCK));*/

    close(s);
    //close(r);
    return 0;
}