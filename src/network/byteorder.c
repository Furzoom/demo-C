#include <stdio.h>

void byteorder()
{
    union 
    {
        short value;
        char union_bytes[sizeof(short)];
    }test;

    test.value = 0x0102;
    if (test.union_bytes[0] == 1 && test.union_bytes[1] == 2)
    {
        printf("Big-endian\n");
    }
    else if (test.union_bytes[0] == 2 && test.union_bytes[1] == 1)
    {
        printf("Little-endian\n");
    }
    else
    {
        printf("Unkown...\n");
    }
}

int main(int argc, char *argv[])
{
    byteorder();
    return 0;
}

