#include "unp.h"

int main(int argc, char *argv[])
{
  int val;

  if ((val = fcntl(STDIN_FILENO, F_GETFL)) < 0)
  {
    err_sys("F_GETFL failed");
  }

  printf("STDIN FLAG: %x\n", val);

  val |= O_NONBLOCK;
  if (fcntl(STDIN_FILENO, F_SETFL, val) < 0)
  {
    err_sys("F_SETFL failed");
  }

  if ((val = fcntl(STDIN_FILENO, F_GETFL)) < 0)
  {
    err_sys("F_GETFL failed");
  }
  printf("After set STDIN NONBLOCK\n");
  printf("STDIN FLAG: %x\n", val);

  return 0;
}

