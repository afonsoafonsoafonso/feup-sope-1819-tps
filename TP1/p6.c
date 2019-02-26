#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define BUF_LENGTH 256 
int main(int argc,char **argv) {   
    FILE *src, *dst;
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
        exit(0);  // zero é geralmente indicativo de "sucesso" 
}
