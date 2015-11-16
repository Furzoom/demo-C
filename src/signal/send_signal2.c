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
    signal(SIGALRM, ouch);
    alarm(5); 
    pause();
    if (alarm_fired)
        printf("\nI got a signal %d\n", SIGALRM);

    exit(0);
}
