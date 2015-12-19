#include <stdio.h>

#define msg "Score is error!\n"

int main()
{
    int score;
    while (EOF != scanf("%d", &score))
    {
        if (score > 100)
            printf(msg);
        else if (score > 90)
            printf("A\n");
        else if (score > 80)
            printf("B\n");
        else if (score > 70)
            printf("C\n");
        else if (score > 60)
            printf("D\n");
        else if (score > 0)
            printf("E\n");
        else
            printf(msg);
    }
    return 0;
}

