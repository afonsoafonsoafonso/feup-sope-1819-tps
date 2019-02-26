#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv) {
    unsigned char buffer[BUFFER_SIZE];
    int s = open(argv[1], O_RDONLY);
    int r = open(argv[2], O_WRONLY | O_TRUNC);

    //diferença entre isto e solução é que solução lê muitos mais chars de uma vez???
    while(read(s,buffer,1)!=0) {
        write(r,buffer,1);
    }

    close(s);
    close(r);
    return 0;
}