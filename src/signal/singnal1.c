#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("\nOUCH! - I got signal %d\n", sig);
    /* set signal to default */
    sleep(3);
    signal(SIGINT, SIG_DFL);
}

int main()
{
    signal(SIGINT, ouch);
    /* use 2 CTRL-C to terminate */
    while(1)
    {
        printf("Hello world!\n");
        sleep(1);
    }
    return 0;
}

