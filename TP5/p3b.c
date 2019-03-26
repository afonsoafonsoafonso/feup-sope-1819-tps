#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1
#define BUFFER 512

int main(int argc, char **argv) {
    pid_t pid;
    int fd[2], nr;
    char buffer[BUFFER];

    pipe(fd);
    pid = fork();

    //porque é que já funciona se trocar o código do filho pelo do pai?
    if(pid > 0) {
        close(fd[WRITE]);
        dup2(fd[READ],STDIN_FILENO);
        execlp("sort","sort");
        exit(1);
    }
    else {
        close(fd[READ]);
        int file = open(argv[1],O_RDONLY);
        dup2(fd[WRITE],STDOUT_FILENO);
        execlp("cat","cat",argv[1]);
    }
    return 0;
}