#include <stdio.h>
#include <ctype.h>

int main()
{
    int i, space;
    char in[101];
    while (fgets(in, sizeof(in), stdin))
    {
        i = 0;
        space = 1;
        while (in[i] && in[i] != '\n')
        {
            if (space && !isblank(in[i]))
            {
                in[i] = in[i] - 32;
                space = 0;
            }
            else if (isblank(in[i]))
            {
                space = 1;
            }
            i++;
        }
        printf(in);
    }
    return 0;
}

