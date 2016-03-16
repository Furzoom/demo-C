/*
 * open file
 */

#include "unp.h"

int main()
{
    int fd;
    //if ((fd = open("test.txt", O_RDONLY)) == -1)
    //if ((fd = open("test.txt", O_WRONLY)) == -1)
    //if ((fd = open("test.txt", O_WRONLY | O_CREAT)) == -1)
    //if ((fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR)) == -1)
    if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
        err_sys("open error");
    close(fd);
    return 0;
}
