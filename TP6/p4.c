#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

void* thrfunc(void* arg) {
    sleep(1);
    printf("My TID is: %d! ; My no. is: %d!\n", (int)pthread_self(), *(int*)arg);
    return arg;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nos[10] = {0,1,2,3,4,5,6,7,8,9};
    int *r;

    for(int i=0; i<NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thrfunc, (void*)&thread_nos[i]);
    }
8
    for(int j=0; j<NUM_THREADS; j++) {
        pthread_join(threads[j],(void**)&r);
        printf("Return of thread no.%d was: %d\n", thread_nos[j], *r);
    }

    return 0;
}