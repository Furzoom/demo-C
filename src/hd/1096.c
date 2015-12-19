#include <stdio.h>

int main()
{
    int n, sub_n, sum, a;
    scanf("%d", &n);
    while (n --)
    {
        scanf("%d", &sub_n);
        sum = 0;
        while (sub_n --)
        {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
        if (n != 0)
            printf("\n");
    }
    return 0;
}

