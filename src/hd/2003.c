#include <stdio.h>

int main()
{
    double num;
    while (EOF != scanf("%lf", &num))
    {
        printf("%.2lf\n", num > 0 ? num : -num);
    }
    return 0;
}

