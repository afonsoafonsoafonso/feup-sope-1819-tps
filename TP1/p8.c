#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char**argv) {
    srand(time(NULL));
    //clock_t begin = clock();
    int rand_no=-1;
    while(rand_no!=atoi(argv[2])) {
        rand_no = rand() % (atoi(argv[1])+1);
        printf("%d\n",rand_no);
    }
    //clock_t end = clock();
    //double time_spent = (double)(end-begin) / sysconf(_SC_CLK_TCK);
    //printf("%f\n",time_spent);
    struct tms *tempos = malloc(sizeof(struct tms));
    times(tempos);
    printf("%f\n",(float)tempos->tms_utime/sysconf(_SC_CLK_TCK));
    printf("%f\n\n",(float)tempos->tms_stime/sysconf(_SC_CLK_TCK));
    return 0;
}