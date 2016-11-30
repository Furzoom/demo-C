/*
 * link()
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    if (argc <= 2)
        err_quit("Usage: %s <oldpath> <newpath>", argv[0]);
    if (access(argv[1], F_OK) == -1)
        err_sys(argv[1]);
    if (access(argv[2], F_OK) == 0)
        err_msg("%s is existed", argv[2]);
    if (link(argv[1], argv[2]) == -1)
        err_msg("link error");
    return 0;
}
