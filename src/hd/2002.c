#include <stdio.h>

#define PI 3.1415927

int main()
{
    double radius;
    while (EOF != scanf("%lf", &radius))
    {
        printf("%.3lf\n", PI * 4 / 3 * radius * radius * radius);
    }
    return 0;
}

