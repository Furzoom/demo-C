#include <stdio.h>
#include <string.h>

int main()
{
    char in[101];
    int len, c, i;
    while (fgets(in, sizeof(in), stdin))
    {
        len = strlen(in);
        in[--len] = '\0';
        c = in[0];
        for (i = 1; i < len; i++)
        {
            if (in[i] > c)
            {
                c = in[i];
            }
        }
        for (i = 0; i < len; i++)
        {
            putchar(in[i]);
            if (in[i] == c)
            {
                printf("(max)");
            }
        }
        printf("\n");
    }
    return 0;
}

