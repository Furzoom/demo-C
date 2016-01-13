/*
 * 1-5.c - By furzoom @ Jan 10, 2016
 */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("FAHR CELSIUS\n");
    for (fahr = upper; fahr >= lower; fahr = fahr - step) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }
    return 0;
}

