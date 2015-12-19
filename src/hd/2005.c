#include <stdio.h>

int DAYS_YEAR[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int main()
{
    int y, m, d, days;
    while (EOF != scanf("%d/%d/%d", &y, &m, &d))
    {
        days = DAYS_YEAR[m - 1] + d;
        if (m > 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
            days += 1;
        printf("%d\n", days);
    }
    return 0;
}

