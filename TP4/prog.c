#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if(argc!=2) {
        printf("Wrong usage!\n");
    }
        printf("%s\n",argv[1]);
    for(int i=0; i<6; i++) {
        sleep(5);
        printf("%s\n",argv[1]);
    }
    printf("30 second have passed. Program will terminate\n");
    return 0;
}