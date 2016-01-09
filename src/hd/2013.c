#include <stdio.h>

int main()
{
    int count, d;
    while (EOF != scanf("%d", &d))
    {
        count = 1;
        while (-- d)
            count = 2 * count + 2;
        printf("%d\n", count);
    }
    return 0;
}

