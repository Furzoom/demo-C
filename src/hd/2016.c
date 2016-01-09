#include <stdio.h>

#define N 100

int main()
{
    static int array[N];
    int n, temp, min_index, i;
    while (EOF != scanf("%d", &n) && n != 0)
    {
        i = 0;
        while (i < n)
        {
            scanf("%d", &array[i ++]);
        }
        min_index = 0;
        for (i = 1; i < n; i ++)
        {
            if (array[min_index] > array[i])
                min_index = i;
        }
        temp = array[0];
        array[0] = array[min_index];
        array[min_index] = temp;
        for (i = 0; i < n - 1; i ++)
        {
            printf("%d ", array[i]);
        }
        printf("%d\n", array[i]);
    }
    return 0;
}

