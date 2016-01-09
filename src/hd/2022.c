#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : (-(x)))

int main()
{
    int m, n, sm, sn, score, sscore, i, j;
    while (EOF != scanf("%d%d", &m, &n))
    {
        sm = sn = 1;
        sscore = 0;
        for (i = 0; i < m; i ++)
        {
            for (j = 0; j < n; j ++)
            {
                scanf("%d", &score);
                if (abs(sscore) < abs(score))
                {
                    sscore = score;
                    sm = i + 1;
                    sn = j + 1;
                }
            }
        }
        printf("%d %d %d\n", sm, sn, sscore);
    }
    return 0; 
}


