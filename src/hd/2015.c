#include <stdio.h>

int main()
{
    int m, n, start;
    while (EOF != scanf("%d%d", &n, &m))
    {
        start = 2;
        while (start + 2 * m - 2 <= 2 * n)
        {
            printf("%d", start + m - 1);
            start = start + 2 * m;
            if (start - 2 != 2 * n)
                printf(" ");
        }
        if (start <= 2 * n && start + 2 * m > 2 * n + 2)
            printf("%d", n + start / 2);
        printf("\n");
    }
    return 0;
}

