#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main()
{
//    open("test.txt", O_WRONLY | O_CREAT, 0);
    fopen("test.txt", "w+");
    printf("Hello furzoom\n");
    return(0);
}
