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

    //Child process
    if(pid == 0)
    {
        printf("child process: pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(5);
        printf("child process: pid = %d, ppid = %d\n", getpid(), getppid());
    }
    //Father process
    else
        printf("father process: pid = %d\n", getpid());

    return 0;
}

