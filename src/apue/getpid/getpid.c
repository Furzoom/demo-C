/*
 * get process ID
 */
#include "unp.h"

int main()
{
    printf("PID : %d\n", getpid());
    printf("PPID: %d\n", getppid());
    return 0;
}
