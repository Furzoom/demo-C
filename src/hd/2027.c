#include <stdio.h>

int main()
{
    int n, i, result[5];
    char in[101];

    scanf("%d", &n);
    getchar();
    while (n--)
    {
        for (i = 0; i < 5; i++)
        {
            result[i] = 0;
        }

        fgets(in, sizeof(in), stdin);
        i = 0;
        while (in[i] && in[i] != '\n')
        {
            switch (in[i])
            {
                case 'a':
                case 'A':
                    result[0] ++;
                    break;
                case 'e':
                case 'E':
                    result[1] ++;
                    break;
                case 'i':
                case 'I':
                    result[2] ++;
                    break;
                case 'o':
                case 'O':
                    result[3] ++;
                    break;
                case 'u':
                case 'U':
                    result[4] ++;
                    break;
                default:
                    break;
            }
            i++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", result[0], result[1], result[2], result[3], result[4]);
        if (n != 0)
        {
            printf("\n");
        }
    }
    return 0;
}
