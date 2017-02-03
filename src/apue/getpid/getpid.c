/*
 * get process ID
 */
#include "unp.h"

int main()
{
    printf("PID : %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("UID:  %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("GID:  %d\n", getgid());
    printf("EGID: %d\n", getegid());

    return 0;
}
