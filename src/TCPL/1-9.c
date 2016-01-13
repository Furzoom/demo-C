/*
 * 1-9.c - By furzoom @ Jan 10, 2016
 */

#include <stdio.h>

int main()
{
    int c, space;

    space = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space != 1) {
                space = 1;
                putchar(c);
            }
        } else {
            space = 0;
            putchar(c);
        }
    }
    return 0;
}

