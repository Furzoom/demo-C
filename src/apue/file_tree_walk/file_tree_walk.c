/**
 * file tree walk
 */

#include "unp.h"
#include <dirent.h>
#include <limits.h>

typedef int Myfunc(const char *, const struct stat *, int);

static Myfunc   myfunc;
static int      myftw(char *, Myfunc *);
static int      dopath(Myfunc *);

static long     nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
    int ret;
    if (argc != 2)
        err_quit("usage: %s <starting-pathname>", argv[0]);
    // do it all
    ret = myftw(argv[1], myfunc);

    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
    // avoid divide by 0
    if (ntot == 0)
        ntot = 1;
    printf("regular files   = %7ld, %5.2f %%\n", nreg, nreg*100.0/ntot);
    printf("directories     = %7ld, %5.2f %%\n", ndir, ndir*100.0/ntot);
    printf("symbolic links  = %7ld, %5.2f %%\n", nslink, nslink*100.0/ntot);
    printf("char special    = %7ld, %5.2f %%\n", nchr, nchr*100.0/ntot);
    printf("block special   = %7ld, %5.2f %%\n", nblk, nblk*100.0/ntot);
    printf("sockets         = %7ld, %5.2f %%\n", nsock, nsock*100.0/ntot);
    printf("FIFOs           = %7ld, %5.2f %%\n", nfifo, nfifo*100.0/ntot);
    return 0;
}

#define FTW_F   1   // file
#define FTW_D   2   // directory
#define FTW_DNR 3   // directory that can't read
#define FTW_NS  4   // file that can't stat

static char *fullpath; // full pathname
static int myftw(char *pathname, Myfunc *func)
{
    int len = 1024;
    fullpath = (char *)malloc(len);
    strncpy(fullpath, pathname, len);
    fullpath[len - 1] = 0;
    return(dopath(func));
}

static int dopath(Myfunc *func)
{
    struct stat     statbuf;
    struct dirent   *dirp;
    DIR             *dp;
    int             ret;
    char            *ptr;
    if (lstat(fullpath, &statbuf) < 0)
        return (func(fullpath, &statbuf, FTW_NS));
    if (S_ISDIR(statbuf.st_mode) == 0)
        return (func(fullpath, &statbuf, FTW_F));
    if ((ret = func(fullpath, &statbuf, FTW_D)) != 0)
        return (ret);
    ptr = fullpath + strlen(fullpath);
    *ptr++ = '/';
    *ptr = 0;
    if ((dp = opendir(fullpath)) == NULL)
        return (func(fullpath, &statbuf, FTW_DNR));
    while ((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 ||
            strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(ptr, dirp->d_name);
        if ((ret = dopath(func)) != 0)
            break;
    }
    ptr[-1] = 0;
    if (closedir(dp) < 0)
        err_ret("can't close directory %s", fullpath);
    return ret;
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
    switch (type)
    {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT)
            {
                case S_IFREG:
                    nreg++;
                    break;
                case S_IFBLK:
                    nblk++;
                    break;
                case S_IFCHR:
                    nchr++;
                    break;
                case S_IFIFO:
                    nfifo++;
                    break;
                case S_IFLNK:
                    nslink++;
                    break;
                case S_IFSOCK:
                    nsock++;
                    break;
                case S_IFDIR:
                    err_dump("for S_IFDIR for %s", pathname);
            }
            break;
        case FTW_D:
            ndir++;
            break;
        case FTW_DNR:
            err_ret("can't read directory %s", pathname);
            break;
        case FTW_NS:
            err_ret("stat error for %s", pathname);
            break;
        default:
            err_dump("unknown type %d for pathnaem %", type, pathname);
            break;
    }
    return 0;
}

