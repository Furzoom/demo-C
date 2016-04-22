#include <stdio.h>
#include <string.h>

#define t_start(c) ((c) == '_' || ((c) >= 'a' && (c) <= 'z') \
        || ((c) >= 'A' && (c) <= 'Z'))
#define t_al(c) ((t_start(c)) || ((c) >= '0' && (c) <= '9'))

int main()
{
    int n, len, is_ok, i;
    char in[51];

    scanf("%d", &n);
    getchar();
    while (n--)
    {
        fgets(in, sizeof(in), stdin);
        len = strlen(in);
        in[--len] = '\0';

        is_ok = 1;
        if (!t_start(in[0]))
        {
            is_ok = 0;
        }

        i = 1;
        while (i < len && is_ok && t_al(in[i]))
        {
            i++;
        }

        if (is_ok && i == len)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
