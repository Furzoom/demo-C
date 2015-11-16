#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int alarm_fired = 0;

void ouch(int sig)
{
    alarm_fired = 1;
}

int main()
{
    pid_t pid;
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed\n");
        exit(1);
    case 0:
        // child
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    default:;
    }

    signal(SIGALRM, ouch);
    while(!alarm_fired)
    {
        printf("Hello world!\n");
        sleep(1);
    }
    if (alarm_fired)
        printf("\nI got a signal %d\n", SIGALRM);

    exit(0);
}
