#include <stdio.h>

int main()
{
    int n, count, year, n2, n1, temp;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        if (n < 4)
        {
            printf("%d\n", n);
        }
        else
        {
            n1 = 2;
            n2 = 1;
            year = 3;
            count = 3;
            while (year < n)
            {
                temp = count;
                count += n2;
                n2 = n1;
                n1 = temp;
                year ++;
            }
            printf("%d\n", count);
        }
    }
    return 0;
}

