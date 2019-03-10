#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv) {
    int f, nr, nw;
    unsigned char buffer[BUFFER_SIZE];

    if(argc!=2) {
        printf("Wrong usage: argc->%d\n",argc);
        return 1;
    }

    f = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
    if(f == -1) {
        perror(argv[1]);
        //perror("Error:");
        return 2;
    }

    while((nr = read(STDIN_FILENO,buffer,BUFFER_SIZE)) > 0) {
        if(nr <= 1) break;

        if((nw = write(f,buffer,nr)) <= 0 || nw!=nr) {
            perror(argv[1]);
            close(f);
            return 4;
        }
    }
    close(f);
    return 0;
}
