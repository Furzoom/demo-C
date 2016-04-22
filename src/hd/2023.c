#include <stdio.h>

int main()
{
    int n, m, i, j, in, count;
    int score[50][5], total_stu;
    double total[5];

    while (EOF != scanf("%d%d", &n, &m))
    {
        for (i = 0; i < m; i++)
        {
            total[i] = 0.0;
        }
        for (i = 0; i < n; i++)
        {
            total_stu = 0;
            for (j = 0; j < m; j++)
            {
                scanf("%d", &in);
                score[i][j] = in;
                total_stu += in;
                total[j] += in;
            }

            if (i != n - 1)
            {
                printf("%.2f ", (double)total_stu / m); 
            }
            else
            {
                printf("%.2f\n", (double)total_stu / m);
            }
        }

        for (i = 0; i < m; i++)
        {
            total[i] /= n;
            if (i != m - 1)
            {
                printf("%.2f ", total[i]);
            }
            else
            {
                printf("%.2f\n", total[i]);
            }
        }

        count = 0;
        for (i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if ((double)score[i][j] < total[j])
                {
                    break;
                }
                else if (j == m - 1)
                {
                    count ++;
                }
            }
        }
        printf("%d\n\n", count);
    }

    return 0;
}
