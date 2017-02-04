#include "unp.h"
#include <signal.h>

static void sig_usr(int);

int main(int argc, char *argv[])
{
    int i;
    struct timeval starttime, endtime;
    long timeuse;

    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("can't catch SIGUSR1");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        err_sys("can't cathc ISGUSR2");
    i = 0;

    gettimeofday(&starttime, NULL);
    while (++i)
    {
        sleep(1);
        gettimeofday(&endtime, NULL);
        timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) +
            (endtime.tv_usec - starttime.tv_usec);
        printf("output %12ld\n", timeuse);
        starttime = endtime;
    }

    return 0;
}

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        err_dump("received signal %d\n", signo);
    sleep(5);
}
