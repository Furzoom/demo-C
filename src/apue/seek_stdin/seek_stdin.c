/*
 * lseek
 */

#include "unp.h"

int main()
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        perror("Cannot seek");
    else 
        printf("Seek OK\n");
    return 0;
}
