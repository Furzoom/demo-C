/**
 * getcwd
 */

#include "unp.h"

int main(int argc, char *argv[])
{
  char buf[MAXLINE] = {'0'};
  const char *wd = "/usr";

  if (getcwd(buf, sizeof buf) == NULL) {
    err_sys("getcwd failed");
  }

  printf("Current working is %s\n", buf);

  if (chdir(wd) == -1) {
    err_sys("Can't change working directory to %s", wd);
  }

  if (getcwd(buf, sizeof buf) == NULL) {
    err_sys("getcwd failed");
  }
  printf("After change working directory: %s\n", buf);

  return 0;
}
