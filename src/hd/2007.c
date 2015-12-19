#include <stdio.h>

int main()
{
    int odd_result, even_result, start, end;
    while (EOF != scanf("%d%d", &start, &end))
    {
        odd_result = 0;
        even_result = 0;
        if (start > end)
        {
            start ^= end;
            end ^= start;
            start ^= end;
        }

        while (start <= end)
        {
            if (start % 2 == 0)
            {
                even_result += start * start;
            }
            else
            {
                odd_result += start * start * start;
            }
            start++;
        }
        printf("%d %d\n", even_result, odd_result);
    }
    return 0;
}

