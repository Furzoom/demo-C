#include "unp.h"

int main(int argc, char *argv[])
{
  struct stat st;
  char *ptr;

  if (argc < 2) {
    err_quit("Usage: %s <filename>\n", argv[0]);
  }

  // follow the symbolic link
  if (stat(argv[1], &st) < 0) {
    err_sys("stat failed");
  }

  if (S_ISREG(st.st_mode)) {
    ptr = "regular";
  } else if (S_ISDIR(st.st_mode)) {
    ptr = "directory";
  } else if (S_ISBLK(st.st_mode)) {
    ptr = "block";
  } else if (S_ISCHR(st.st_mode)) {
    ptr = "character";
  } else if (S_ISLNK(st.st_mode)) {
    ptr = "symbolic link";
  } else if (S_ISSOCK(st.st_mode)) {
    ptr = "socket";
  } else if (S_ISFIFO(st.st_mode)) {
    ptr = "fifo";
  } else {
    ptr = "unknown";
  }

  printf("%s\n", ptr);

  return 0;
}


