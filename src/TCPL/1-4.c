/*
 * 1-4.c - By furzoom @ Jan 10, 2016
 */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    printf("CELSIUS FAHR\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = 9.0 / 5.0 * celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}

