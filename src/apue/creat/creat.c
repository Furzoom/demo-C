#include "unp.h"

int main(int argc, char *argv[])
{
  const char *filename = "test.txt";
  int fd;
  char buf[MAXLINE] = {'\0'};

  /**
   * creat equivalent to
   * open(path, O_WRONLY | O_CREAT | O_TRUNC, mode)
   */
  if ((fd = creat(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
  {
    err_sys("Can't create %s", filename);
  }
  else
  {
    printf("Create %s success\n", filename);
  }

  /**
   * EBADF bad file descriptor
   */
  if (read(fd, buf, sizeof buf) <= 0)
  {
    err_sys("Read failed");
  }
  close(fd);

  return 0;
}
