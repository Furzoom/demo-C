/*
 * chown() fchown() lchown()
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
        err_quit("usage: %s <path>", argv[0]);
    if (access(argv[1], F_OK) == -1)
        err_sys("access %s error", argv[1]);
    if (chown(argv[1], 0, -1) == -1)
        err_sys("chown %s error", argv[1]);
    return 0;
}
