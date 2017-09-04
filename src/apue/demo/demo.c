#include "unp.h"
#include <sys/param.h>

int main(int argc, char *argv[])
{
#ifdef MAXPATHLEN
  printf("MAXPATHLEN: %d\n", MAXPATHLEN);
#else
  printf("Not define MAXPAHTLEN\n");
#endif
  printf("PATH_MAX: %d\n", PATH_MAX);
  return 0;
}

