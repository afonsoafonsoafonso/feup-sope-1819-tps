#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/times.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv) {
    FILE *s = fopen(argv[1],"r");
    FILE *d = fopen(argv[2],"w");
    char c;
    while(c!=EOF) {
        c=fgetc(s);
        fputc(c,d);
    }

    struct tms *tempos = malloc(sizeof(struct tms));
    times(tempos);
    printf("utime: %.50f\n",(float)tempos->tms_utime/sysconf(_SC_CLK_TCK));
    printf("stime: %.50f\n\n",(float)tempos->tms_stime/sysconf(_SC_CLK_TCK));

    fclose(s);
    fclose(d);
    return 0;
}