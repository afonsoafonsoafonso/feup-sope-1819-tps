#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thrsum (void* ops) {
    int *a = (int*)ops;
    int *value = malloc(sizeof(int));
    *value = a[0]+a[1];
    return value;
}

void* thrsub (void* ops) {
    int *a = (int*)ops;
   int *value = malloc(sizeof(int));
    *value = a[0]-a[1];
    return value;
}

void* thrmult (void* ops) {
    int *a = (int*)ops;
    int *value = malloc(sizeof(int));
    *value = a[0]*a[1];
    return value;
}

void* thrdiv (void* ops) {
    float *a = (float*)ops;
    float *value = malloc(sizeof(int));
    *value = a[0]/a[1];
    return value;
}



int main() {
    int operator[2];
    int a, b;
    int *rsum, *rsub, *rmult;
    float *rdivi;

    printf("Input two numbers: ");
    scanf("%d %d", &a, &b);
    operator[0]=a; operator[1]=b;

    pthread_t sum; pthread_create(&sum, NULL, thrsum, (void*)&operator);
    pthread_t sub; pthread_create(&sub, NULL, thrsub, (void*)&operator);
    pthread_t mult; pthread_create(&mult, NULL, thrmult, (void*)&operator);
    pthread_t divi; pthread_create(&divi, NULL, thrdiv, (void*)&operator);
    
    pthread_join(sum, (void**)&rsum);
    pthread_join(sub, (void**)&rsub);
    pthread_join(mult, (void**)&rmult);
    pthread_join(divi, (void**)&rdivi);


    printf("Sum: %d; Sub: %d; Mult: %d; Divi: %f;\n", *rsum, *rsub, *rmult, *rdivi);

    pthread_exit(0);
}