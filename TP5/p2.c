#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER 512

struct results {
    int a;
    int b;
    int sum;
    int sub;
    float divi;
    int mult;
};

int main(void) {
    int p1[2], p2[2];
    struct results nums;
    pid_t pid;

    pipe(p1);
    pipe(p2);
    pid = fork();

    if(pid>0) {
        close(p1[0]);
        close(p2[1]);
        scanf("%d %d", &(nums.a), &(nums.b));
        write(p1[1],&nums,sizeof(nums));
        read(p2[0],&nums,sizeof(nums));
        printf("sum: %d, sub: %d, div: %f, mult: %d\n",nums.sum, nums.sub, nums.divi, nums.mult);
    }
    else {
        close(p1[1]);
        close(p2[0]);
        read(p1[0],&nums,sizeof(nums));
        nums.sum = nums.a + nums.b;
        nums.sub = nums.a - nums.b;
        nums.divi = (float)nums.a / (float)nums.b;
        nums.mult = nums.a * nums.b;
        write(p2[1],&nums,sizeof(nums));
    }

    return 0;
}        