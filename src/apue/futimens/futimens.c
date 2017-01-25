#include "unp.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    struct timespec times[2];
    struct stat statbuf;
    if (lstat(argv[1], &statbuf) < 0)
    {
        err_sys("%s: stat error", argv[1]);
    }


    times[0] = statbuf.st_atim;
    times[1] = statbuf.st_mtim;

    times[0].tv_sec += 360;
    times[1].tv_sec += 360;

    if (utimensat(AT_FDCWD, argv[1], times, 0) < 0)
    {
        err_sys("%s: utimensat error", argv[1]);
    }

    return 0;
}
