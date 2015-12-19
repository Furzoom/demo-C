#include <stdio.h>

int main()
{
    int n, sum, a;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        sum = 0;
        while (n--)
        {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
    return 0;
}
