/*
 * stat()
 * get file type
 */

#include "unp.h"
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    int i = 1;
    
    if (argc <= 1)
        err_quit("usage: %s <filepath1> ...", argv[0]);
    
    while (i < argc)
    {
        if (lstat(argv[i], &st) == -1)
        {
            perror(argv[i]);
            i++;
            continue;
        }

        if (S_ISREG(st.st_mode))
            printf("regular file\n");
        else if (S_ISDIR(st.st_mode))
            printf("directory\n");
        else if (S_ISCHR(st.st_mode))
            puts("character device");
        else if (S_ISBLK(st.st_mode))
            puts("block device");
        else if (S_ISFIFO(st.st_mode))
            puts("FIFO (named pipe)");
        else if (S_ISLNK(st.st_mode))
            puts("symbolic link");
        else if (S_ISSOCK(st.st_mode))
            puts("socket");
        else
            puts("unknown file type");

        switch (st.st_mode & S_IFMT)
        {
            case S_IFREG:
                puts("regular file");
                break;
            case S_IFDIR:
                puts("directory");
                break;
            case S_IFCHR:
                puts("character device");
                break;
            case S_IFBLK:
                puts("block device");
                break;
            case S_IFIFO:
                puts("FIFO (named pipe)");
                break;
            case S_IFLNK:
                puts("symbolic link");
                break;
            case S_IFSOCK:
                puts("socket");
                break;
            default:
                puts("unknown file type");
                break;
        }
        printf("I-node number:     %ld\n", (long)st.st_ino);
        printf("Link count:        %ld\n", (long)st.st_nlink);
        printf("blksize:           %ld\n", (long)st.st_blksize);
        printf("file size:         %ld\n", (long)st.st_size);
        printf("block allocated:   %ld\n", (long)st.st_blocks);
        printf("Access time:       %s", ctime(&st.st_atime));
        printf("Modification time: %s", ctime(&st.st_mtime));
        printf("Change time:       %s", ctime(&st.st_ctime));

        i++;
    }
    return 0;
}

