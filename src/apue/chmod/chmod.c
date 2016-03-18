/*
 * chmod() fchmod()
 */

#include "unp.h"

int main()
{
    struct stat st;
    if (stat("foo", &st) < 0)
        err_sys("stat error for foo");
    if (chmod("foo", (st.st_mode & ~S_IXGRP) | S_ISGID) < 0)
        err_sys("chmod error for foo");
    // set rw-r--r--
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        err_sys("chmod error for bar");
    return 0;
}
