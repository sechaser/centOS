#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();

    if(pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("child process\n");
        exit(1);
    }

    printf("father process");
    sleep(4);

    system("ps -o pid,ppid,state,tty,command");

    return 0;
}

