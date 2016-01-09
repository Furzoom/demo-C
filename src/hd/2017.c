#include <stdio.h>

int main()
{
    int n, count, c;
    scanf("%d", &n);
    getchar();
    while (n --)
    {
        count = 0;
        while ((c = getchar()) != '\n')
        {
            if (c >= '0' && c <= '9')
                count ++;
        }
        printf("%d\n", count);
    }
    return 0;
}

