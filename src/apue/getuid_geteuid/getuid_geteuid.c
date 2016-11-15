/*
 * getuid()
 * geteuid()
 */
#include "unp.h"

int main()
{
    int fd;
    printf("Process's uid = %d, euid = %d, gid = %d, egid = %d\n",
            getuid(), geteuid(), getgid(), getegid());
    if ((fd = open("makefile", O_RDWR)) == -1)
        err_sys("Open failuer");

    printf("Open successfully!\n");
    close(fd);
    return 0;
}
