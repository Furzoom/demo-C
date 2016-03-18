/*
 * unlink()
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    const char *filename = "foo.txt";
    if (open(filename, O_RDWR) < 0)
        err_sys("open %s error", filename);
    if (unlink(filename) < 0)
        err_sys("unlink %s error", filename);
    printf("%s unlinked\n", filename);
    sleep(15);
    puts("done");

    return 0;
}
