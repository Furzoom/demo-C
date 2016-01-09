#include <stdio.h>

#define N 100
#define abs(x) ((x) > 0 ? (x) : (-(x)))

void sort(int a[], int n);

int main()
{
    static int array[N];
    int n, i;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        i = 0;
        while (i < n)
        {
            scanf("%d", &array[i]);
            i ++;
        }
        sort(array, n);
        for (i = 0; i < n - 1; i ++)
            printf("%d ", array[i]);
        printf("%d\n", array[i]);
    }
    return 0;
}

void sort(int a[], int n)
{
    int temp, i, j, max;
    for (i = 0; i < n - 1; i ++)
    {
        max = i;
        for (j = i + 1; j < n; j ++)
        {
            if (abs(a[max]) < abs(a[j]))
                max = j;
        }
        temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }
}

