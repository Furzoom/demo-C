/*
 * seek behind the end of file
 */

#include "unp.h"

static char buf1[] = "abcdefghij";
static char buf2[] = "ABCDEFGHIJ";
//static char zero_buf[10];

int main()
{
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");
    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    if (lseek(fd, 10240, SEEK_SET) == -1)
        err_sys("lseek error");
    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    close(fd);

    return 0;
}
