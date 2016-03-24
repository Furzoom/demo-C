/*
 * printf() fprintf() sprintf() snprintf()/
 */

#include "unp.h"

int main(int argc, char *argv[])
{
    char c = 'a';
    short s = 32767;
    unsigned short us = 65535;
    int i = 0x7fffffff;
    unsigned int ui = 0xffffffff;
    long l = i;
    unsigned long ul = ui;
    long long ll = 0x7fffffffffffffff;
    unsigned long long ull = 0xffffffffffffffff;
    float f = 1234567890.123456789;
    float f1 = 1234.56789;
    double d = 1234567890.123456789;
    char str[] = "Welcome to furzoom";
    unsigned int count;

    printf("|%-20d|\n", i);
    printf("|%+20d|\n", i);
    printf("|% d|\n", i);
    printf("|%#20d|\n", i);
    printf("|%#20X|\n", i);
    printf("|%020d|\n", i);
    printf("--------------\n");
    printf("|%10.3f|\n", f);
    printf("|%10.3f|\n", f1);
    printf("|%.10s|\n", str);
    printf("|%20.10s|\n", str);
    printf("|%*.*s|\n", 10, 5, str);
    printf("--------------\n");
    printf("|%hhc|\n", c);
    printf("|%hd|\n", s);
    printf("|%ld|\n", l);
    printf("|%lld|\n", ll);
    printf("--------------\n");
    printf("|%lld|%n\n", ll, &count);
    printf("|%u|\n", count);

    return 0;
}
