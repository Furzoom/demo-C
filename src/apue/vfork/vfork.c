#include "unp.h"

int glob = 1;

int main(int argc, char *argv[])
{
    int var;
    pid_t pid;

    var = 88;
    printf("before vfork\n");
    if ((pid = vfork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        glob ++;
        var ++;
        exit(0);
    }
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}

