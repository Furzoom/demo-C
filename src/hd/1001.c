#include <stdio.h>

int main()
{
    int n;
    while (EOF != scanf("%d", &n)) 
    {
        printf("%d\n\n", ((long long)n + 1) * n / 2);
    }
    return 0;
}

