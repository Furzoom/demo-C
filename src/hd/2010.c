#include <stdio.h>

static int flower[] = {153, 370, 371, 407};

int main()
{
    int m, n, i, start, end, flag;
    while (EOF != scanf("%d%d", &m, &n))
    {
        i = 0;
        start = end = 0;
        while (i < sizeof(flower) / sizeof(int))
        {
            if (m > flower[i])
                start = i + 1;
            if (n >= flower[i])
                end = i + 1;
            i++;
        }
        if (start < end)
        {
            flag = 0;
            while (start < end)
            {
                if (flag == 0)
                {
                    flag = 1;
                }
                else
                {
                    printf(" ");
                }
                printf("%d", flower[start++]);
            }
            printf("\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

