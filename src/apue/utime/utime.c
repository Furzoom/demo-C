/*
 * utime
 */

#include "unp.h"
#include <utime.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        err_ret("usage: %s <filename>", argv[0]);
    struct utimbuf utb;
    utb.actime = 0;
    utb.modtime = 3600;

    if (utime(argv[1], &utb) == -1)
        err_sys("utime error");
    else
        puts("utime success");
    return 0;
}
