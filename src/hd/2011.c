#include <stdio.h>

int main()
{
    int m, n, sign, i;
    double result;
    scanf("%d", &m);
    while (m --)
    {
        scanf("%d", &n);
        sign = 1;
        result = i = 0;
        while (i ++ < n)
        {
            if (sign == 1)
                result += 1.0 / i;
            else 
                result -= 1.0 / i;
            sign = -sign;
        }
        printf("%.2lf\n", result);
    }
    return 0;
}

