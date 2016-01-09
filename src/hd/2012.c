#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, num, prime, i, end;
    while (EOF != scanf("%d%d", &x, &y) && !(x == 0 && y == 0))
    {
        prime = 1;
        while (x <= y)
        {
            num = x * x + x + 41;
            if (num % 2 == 0)
                prime = 0;
            end = (int)sqrt(num) + 1;
            i = 3;
            while (prime == 1 && i <= end)
            {
                if (num % i == 0)
                    prime = 0;
                i += 2;
            }
            if (prime == 0)
                break;
            x ++;
        }
        if (prime == 1)
            printf("OK\n");
        else
            printf("Sorry\n");
    }
    return 0;
}
