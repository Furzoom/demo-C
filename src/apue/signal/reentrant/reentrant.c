#include "unp.h"
#include <pwd.h>

static void my_alarm(int signo)
{
    if (signal(SIGALRM, my_alarm) == SIG_ERR)
        err_sys("signal error");
    struct passwd *rootptr;
    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
        err_sys("getpwname(root) error");
    if (alarm(1) != 0)
        err_quit("alarm error");
}

int main(int argc, char *argv[])
{
    struct passwd *ptr;
    if (signal(SIGALRM, my_alarm) == SIG_ERR)
        err_sys("signal error");
    if (alarm(1) != 0)
        err_sys("alarm error");
    while (1)
    {
        //pause();
        if ((ptr = getpwnam("mn")) == NULL)
            err_sys("getpwnam(mn) error");
        if (strcmp(ptr->pw_name, "mn") != 0)
            printf("return value corrupted! pw_name = %s\n",
                   ptr->pw_name);
    }
    return 0;
}
