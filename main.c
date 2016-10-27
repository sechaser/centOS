#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void test1()
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
}

void test2()
{
    pid_t pid;

    while(1)
    {
        pid = fork();
        if(pid < 0)
        {
            perror("fork error\n");
            exit(1);
        }
        else if(pid == 0)
        {
            printf("child process\n");
            exit(1);
        }
        else
        {
            sleep(3);
            system("ps -o pid,ppid,state,tty,command");
            continue;
        }
    }

    return 0;
}

int main(void)
{
    test2();

    return 0;
}

