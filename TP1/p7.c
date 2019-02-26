#include <stdio.h>

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define BUF_LENGTH 256 

void atexit_handler1() {
    printf("Executing handler 1\n");
    return;
}

void atexit_handler2() {
    printf("Executing handler 2\n");
    return;
}

int main(int argc,char **argv) {   
    FILE *src, *dst;
    atexit(atexit_handler1);
    atexit(atexit_handler1);
    atexit(atexit_handler2);
    char buf[BUF_LENGTH];  
    if(argc!=3) {

        printf("Usage: nome_do executável file1 file2\n");
        exit(3);
    }

    if ( ( src = fopen(argv[1], "r" ) ) == NULL ){
        //printf("Error: %s\n", strerror(errno));
        perror("fodeu");
        exit(1);
    }   
    if ( ( dst = fopen(argv[2], "w" ) ) == NULL ){
        perror("fodeu");
        exit(2);
    }   
    while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ){
        fputs( buf, dst );}   
        fclose( src );
        fclose( dst );
        printf("Main done!\n"); 
        exit(0);  // zero é geralmente indicativo de "sucesso" 
}