#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 50000

int ig = 50000;

void * thrfunc(void * arg) {
    int i=0;
    
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    while(ig!=0) {
        ig--;
        i++;
        write(STDERR,arg,1);

    }
    return i;
}

int main() {
    void* r;
    pthread_t ta, tb;

    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");

    pthread_join(ta,&r);
    printf("Thread 1 return: %d\n", (int*)r);
    pthread_join(tb,&r);
    printf("Thread 2 return: %d\n", (int*)r);

    return 0;
}