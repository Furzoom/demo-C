#include "unp.h"

int main(int argc, char *argv[])
{
  const char *filename = "test.txt";
  char buf[MAXLINE] = {'\0'};
  int fd, new_fd;
  off_t offset;

  if ((fd = open(filename, O_RDONLY)) < 0)
  {
    err_sys("Can't open %s", filename);
  }

  // read a byte
  if ((read(fd, buf, 1)) < 1)
  {
    err_sys("Read %s", filename);
  }

  if ((new_fd = dup(fd)) < 0)
  {
    err_sys("dup %d", fd);
  }

  offset = lseek(fd, 0, SEEK_CUR);
  printf("Offset of old fd is %ld\n", offset);
  offset = lseek(new_fd, 0, SEEK_CUR);
  printf("Offset of new fd is %ld\n", offset);

  close(fd);
  close(new_fd);

  return 0;
}

