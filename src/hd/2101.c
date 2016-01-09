#include <stdio.h>

int main()
{
    int a, b;
    while (EOF != scanf("%d%d", &a, &b))
    {
        if ((a + b) % 86 == 0)
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0;
}

