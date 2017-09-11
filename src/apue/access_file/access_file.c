/*
 * access()
 * use real user's ID
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        err_quit("usage: %s <pathname>", argv[0]);
    if (access(argv[1], F_OK) < 0)
        err_quit("file %s does not exist", argv[1]);

    if (access(argv[1], R_OK) < 0)
        err_ret("access error for %s", argv[1]);
    else
        puts("read access OK");

    if (open(argv[1], O_RDONLY) < 0)
        err_ret("open error for %s", argv[1]);
    else 
        puts("open for reading OK");
    return 0;
}
