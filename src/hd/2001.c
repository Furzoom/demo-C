#include <stdio.h>
#include <math.h>

#define ESP 0.000001f

int main()
{
    double x1, y1, x2, y2, distance;
    while (EOF != scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2))
    {
        distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        printf("%.2lf\n", distance);
    }
    return 0;
}
