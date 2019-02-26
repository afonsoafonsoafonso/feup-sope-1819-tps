#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    const char s[2] = " ";
    char *token;
    int i=0;
    fgets(input,100,stdin);

    token = strtok(input,s);

    while(token != NULL) {
        //printf("%s\n",token);
        token=strtok(NULL,s);
        tokens[i]=malloc(sizeof(char)*strlen(token));
        tokens[i]=token;
        i++;
    }

    for(int j=0; j<i; j++) {
        printf("%s\n",tokens[i]);
    }
    return 0;
}