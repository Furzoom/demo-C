/*
 * list files in a directory
 */
#include "unp.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        err_quit("usage: %s directory_name", argv[0]);

    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("inode: %lu\n", dirp->d_ino);
        printf("offset: %lu\n", dirp->d_off);
        printf("record length: %hu\n", dirp->d_reclen);
        printf("type: %u\n", dirp->d_type);
        printf("filename: %s\n", dirp->d_name);
        printf("\n");
    }

    closedir(dp);
    return 0;
}
