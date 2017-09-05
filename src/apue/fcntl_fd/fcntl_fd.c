#include "unp.h"

int main(int argc, char *argv[])
{
  int val;

  if ((val = fcntl(STDIN_FILENO, F_GETFD, 0)) < 0)
  {
    err_sys("F_GETFD failed");
  }

  printf("STDIN FD: %x\n", val);

  if (fcntl(STDIN_FILENO, F_SETFD, FD_CLOEXEC) < 0)
  {
    err_sys("F_SETFD failed");
  }

  if ((val = fcntl(STDIN_FILENO, F_GETFD, 0)) < 0)
  {
    err_sys("F_GETFD failed");
  }
  printf("After set STDIN FD_CLOEXEC\n");
  printf("STDIN FD: %x\n", val);

  return 0;
}