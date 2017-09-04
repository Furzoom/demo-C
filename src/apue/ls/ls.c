/**
 * Directory operation
 */
#include "unp.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  if (argc < 2) {
    err_quit("Usage: %s <directory_name>\n", argv[0]);
  }

  if ((dp = opendir(argv[1])) == NULL) {
    err_sys("Can't open '%s'", argv[1]);
  }

  while ((dirp = readdir(dp)) != NULL) {
    printf("%ld\t%d\t%s\n", dirp->d_ino, dirp->d_type,
           dirp->d_name);
  }

  if (0 != closedir(dp)) {
    err_sys("Close directory %s error", argv[1]);
  }
  return 0;
}
