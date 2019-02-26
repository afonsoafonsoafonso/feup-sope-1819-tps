#include <stdio.h>

int main(int argc, char **argv) {
    FILE *s = fopen(argv[1],"r");
    FILE *d = fopen(argv[2],"w");
    char c;
    while(c!=EOF) {
        c=fgetc(s);
        fputc(c,d);
    }
    fclose(s);
    fclose(d);
    return 0;
}