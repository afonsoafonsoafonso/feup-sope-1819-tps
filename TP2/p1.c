#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASSWD_LEN 20

int main(void) {
    struct termios oldterm, newterm;
    tcgetattr(STDIN_FILENO, &oldterm);
    newterm=oldterm;
    char password[MAX_PASSWD_LEN+1];
    char echo='*';
    char ch;
    int i=0;

    //newterm.c_lflag &= ~(ECHO);
    newterm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newterm);

    write(STDOUT_FILENO,"\nPassword: ",11);
    while(1) {
        read(STDIN_FILENO,&ch,1);
        if(ch=='\n') break;
        password[i]=ch;
        write(STDOUT_FILENO,&echo,1);
        i++;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    write(STDOUT_FILENO,"\nTyped password: ",17);
    write(STDOUT_FILENO, password, strlen(password));
    write(STDOUT_FILENO,"\n",1);

    return 0;
}