#include <stdio.h>

#define N 100

int main()
{
    static int array[N];
    int m, n, i, flag;
    while (EOF != scanf("%d%d\n", &n, &m) && !(n == 0 && m == 0))
    {
        for (i = 0; i < n; i ++)
        {
            scanf("%d", &array[i]);
        }
        flag = 0;
        for (i = 0; i < n; i ++)
        {
            if (flag == 0 && m < array[i])
            {
                printf("%d ", m);
                flag = 1;
            }
            if (i == n - 1)
            {
                printf("%d", array[i]);
            }
            else
            {
                printf("%d ", array[i]);
            }
        }
        if (flag == 0)
        {
            printf(" %d", m);
        }
        printf("\n");
    }
    return 0;
}

