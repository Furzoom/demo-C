#include <stdio.h>

int main()
{
    int n, positive, negative, zero;
    double num;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        positive = negative = zero = 0;
        while (n --)
        {
            scanf("%lf", &num);
            if (num > 0)
            {
                positive ++;
            }
            else if (num < 0)
            {
                negative ++;
            }
            else
            {
                zero ++;
            }
        }
        printf("%d %d %d\n", negative, zero, positive);
    }
    return 0;
}

