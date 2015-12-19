#include <stdio.h>
#include <math.h>

int main()
{
    double result, n;
    int m;
    while (EOF != scanf("%lf%d", &n, &m))
    {
        result = n;
        while (-- m)
        {
            n = sqrt(n);
            result += n;
        }
        printf("%.2lf\n", result);
    }
    return 0;
}
            
