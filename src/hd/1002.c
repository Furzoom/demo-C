#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define LEN 1001

char add1[LEN];
char add2[LEN];
char result[LEN + 1];

int main()
{
    int n, l1, l2, pos, sign, count;
    n = 0;
    scanf("%d", &count);
    while (n++ < count)
    {
        scanf("%s%s", add1, add2);
        memset(result, 0, sizeof(result));
        l1 = strlen(add1);
        l2 = strlen(add2);
        pos = max(l1, l2);
        sign = 0;
        while (l1 > 0 && l2 > 0)
        {
            l1 --;
            l2 --;
            if (add1[l1] + add2[l2] - '0' + sign > '9')
            {
                result[pos--] = add1[l1] + add2[l2] - '0' + sign - 10;
                sign = 1;
            }
            else
            {
                result[pos--] = add1[l1] + add2[l2] - '0' + sign;
                sign = 0;
            }
        }
        while (l1 > 0)
        {
            l1 --;
            if (add1[l1] + sign > '9')
            {
                result[pos--] = add1[l1] + sign - 10;
                sign = 1;
            }
            else
            {
                result[pos--] = add1[l1] + sign;
                sign = 0;
            }
        }
        while (l2 > 0)
        {
            l2 --;
            if (add2[l2] + sign > '9')
            {
                result[pos--] = add2[l2] + sign - 10;
                sign = 1;
            }
            else
            {
                result[pos--] = add2[l2] + sign;
                sign = 0;
            }
        }
//        printf("pos:%d\tsign:%d--\n", pos, sign);
        if (sign == 1)
            result[pos] = '1';
        else
            result[pos] = '0';

        if (n != 1)
            printf("\n");
        printf("Case %d:\n", n);
        printf("%s + %s = %s\n", add1, add2, result + 1 - sign);
    }

    return 0;
}

