#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER 512

struct nums {
    int a;
    int b;
};

int main(void) {
    int fd[2];
    struct nums ab;
    pid_t pid;

    pipe(fd);
    pid = fork();

    if(pid>0) {
        close(fd[0]);
        scanf("%d %d", &(ab.a), &(ab.b));
        //write(fd[1],ab->a,sizeof(ab->a));
        //write(fd[1],ab->b,sizeof(ab->b));
        write(fd[1],&ab,sizeof(ab));
    }
    else {
        close(fd[1]);
        //read(fd[0],&a,BUFFER);
        //read(fd[0],&b,BUFFER);
        read(fd[0],&ab,BUFFER);
        int sum = ab.a + ab.b;
        int sub = ab.b - ab.b;
        float divi = (float)ab.a / (float)ab.b;
        int mult = ab.b * ab.b;
        printf("sum: %d ; sub: %d ; div: %f ; mult: %d\n",sum, sub, divi, mult);
    }

    return 0;
}     