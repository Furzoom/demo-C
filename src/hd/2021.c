#include <stdio.h>

int main()
{
    int n, total, i, salary;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        total = 0;
        for (i = 0; i < n; i ++)
        {
            scanf("%d", &salary);

            // 100
            total += salary / 100;
            salary %= 100;
            // 50
            total += salary / 50;
            salary %= 50;
            // 10
            total += salary / 10;
            salary %= 10;
            // 5
            total += salary / 5;
            salary %= 5;
            // 2
            total += salary / 2;
            salary %= 2;
            // 1
            total += salary;
        }
        printf("%d\n", total);
    }
    return 0;
}

