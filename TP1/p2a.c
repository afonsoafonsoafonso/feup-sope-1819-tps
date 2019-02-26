#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[], char *envp[]) {
    printf("Hello %s\n",getenv("USER_NAME"));//para 5d export USER_NAME="cenas"
    /*for (int i=0;envp[i]!=NULL;i++)
        if (strncmp(envp[i],"USER=",5)==0)5b
            printf("Hello %s\n",envp[i]+5);
        printf("%s\n",evnp[i]);5a */


    /*for (int x=0;x<atoi(argv[argc-1]);x++){
        printf("Hello,");
        for (int i = 1; i <argc-1;i++)
            printf(" %s",argv[i]);
        printf("!\n");}*/
    return 0;
}