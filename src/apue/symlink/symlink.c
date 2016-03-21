/*
 * symlink()
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    if (argc <= 2)
        err_quit("usage: %s <oldpath> <newpath>", argv[0]);
    if (symlink(argv[1], argv[2]) == -1)
        err_sys("symlink error");
    else
        printf("create %s success\n", argv[2]);
    return 0;
}

