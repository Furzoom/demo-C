#include "unp.h"

int main()
{
    int fd1, fd2;
    const char *filename = "test.txt";
    const char str1[] = "ABCDEFG";
    const char str2[] = "abcdefg";

    if ((fd1 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
    {
        err_sys("open error");
    }
    if ((fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
    {
        err_sys("open error");
    }

    if (write(fd1, str1, strlen(str1)) < strlen(str1))
    {
        err_sys("write error");
    }
    if (write(fd2, str2, strlen(str2)) < strlen(str2))
    {
        err_sys("write error");
    }

    close(fd1);
    close(fd2);
    return 0;
}
