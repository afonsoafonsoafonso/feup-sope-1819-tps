#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    int term_stat;
    if(fork()>0) {
        write(STDOUT_FILENO,"Hello",5);
    }
    else {
        wait(&term_stat);
        write(STDOUT_FILENO," world!\n",8);
        printf("Child termination status: %d\n", term_stat);
    }
    return 0;
}