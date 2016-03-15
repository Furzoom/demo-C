/*
 * getuid()
 * geteuid()
 */
#include "unp.h"

int main()
{
    int fd;
    printf("Process's uid = %d, euid = %d\n", getuid(), geteuid());
    if ((fd = open("test.txt", O_RDWR)) == -1)
        err_sys("Open failuer");

    printf("Open successfully!\n");
    close(fd);
    return 0;
}
