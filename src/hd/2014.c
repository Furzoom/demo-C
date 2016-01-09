#include <stdio.h>
#include <float.h>

int main()
{
    int n, i;
    double average, hi_score, lo_score, score;
    while (EOF != scanf("%d", &n))
    {
        hi_score  = -DBL_MAX;
        lo_score = DBL_MAX;
        average = 0.0;
        i = 0;
        while (i++ < n)
        {
            scanf("%lf", &score);
            average += score;
            if (score < lo_score)
                lo_score = score;
            if (score > hi_score)
                hi_score = score;
        }
        average -= lo_score + hi_score;
        printf("%.2lf\n", average / (n - 2));
    }
    return 0;
}

