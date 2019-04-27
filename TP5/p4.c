#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1
#define BUFFER 512

int main(int argc, char** argv) {
    pid_t pid;
    int fd1[2];

    pipe(fd1);
    pid = fork();


    if(pid > 0) {
        close(fd1[READ]);
        dup2(fd1[WRITE],STDOUT_FILENO);
        execlp("ls","ls",argv[1],NULL);
        printf("Error executing ls\n");
        exit(1);
    }
    else {
        close(fd1[WRITE]);
        int fd2[2];
        pipe(fd2);
        pid=fork();
        
        if(pid > 0) {
            close(fd2[READ]);
            dup2(fd2[WRITE],STDOUT_FILENO);
            execlp("grep","grep",argv[2],NULL);
            printf("Error executing grep\n");
            exit(1);
        }
        else {
            close(fd2[WRITE]);
            execlp("sort","sort",NULL);
            printf("Error executing sort\n");
            exit(1);
        }
    }
    return 0;
}