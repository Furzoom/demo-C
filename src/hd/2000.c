#include <stdio.h>

int main()
{
    char input[4];
    char temp;
    while (EOF != scanf("%4s", input))
    {
        if (input[0] > input[1])
        {
            temp = input[0];
            input[0] = input[1];
            input[1] = temp;
        }
        if (input[0] > input[2])
        {
            temp = input[0];
            input[0] = input[2];
            input[2] = temp;
        }
        if (input[1] > input[2])
        {
            temp = input[1];
            input[1] = input[2];
            input[2] = temp;
        }
        printf("%c %c %c\n", input[0], input[1], input[2]);
    }
    return 0;
}

