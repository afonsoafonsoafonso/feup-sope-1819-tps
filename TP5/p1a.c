#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER 512

    int main(void) {
    int fd[2];
    int a, b;
    pid_t pid;

    pipe(fd);
    pid = fork();

    if(pid>0) {
        close(fd[0]);
        scanf("%d %d", &a, &b);
        write(fd[1],&a,sizeof(a));
        write(fd[1],&b,sizeof(b));
    }
    else {
        close(fd[1]);
        read(fd[0],&a,BUFFER);
        read(fd[0],&b,BUFFER);
        int sum = a + b;
        int sub = a - b;
        float divi = (float)a / (float)b;
        int mult = a * b;
        printf("sum: %d ; sub: %d ; div: %f ; mult: %d\n",sum, sub, divi, mult);
    }

    return 0;
}        