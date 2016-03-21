/*
 * symlink()
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    char buf[20];
    int len;
    if (argc <= 2)
        err_quit("usage: %s <oldpath> <newpath>", argv[0]);
    if (symlink(argv[1], argv[2]) == -1)
        err_sys("symlink error");
    else
        printf("create %s success\n", argv[2]);
    
    if ((len = readlink(argv[2], buf, 20)) == -1)
        err_sys("readlink error");
    if (len > 20 - 1) 
        len = 20 - 1;
    buf[len] = '\0';
    puts(buf);
    return 0;
}

