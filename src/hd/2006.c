#include <stdio.h>

int main()
{
    int n, result, flag, d;
    while (EOF != scanf("%d", &n))
    {
        flag = 0;
        while (n--)
        {
            scanf("%d", &d);
            if (d % 2 == 1)
            {
                if (flag == 0)
                {
                    flag = 1;
                    result = d;
                }
                else
                {
                    result *= d;
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}


