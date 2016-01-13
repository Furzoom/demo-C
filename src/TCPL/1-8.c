/*
 * 1-8.c - By furzoom @ Jan 10, 2016
 */

#include <stdio.h>

int main()
{
    int c;
    long spaces, tabs, new_lines;
    
    spaces = tabs = new_lines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++ spaces;
        } else if (c == '\t') {
            ++ tabs;
        } else if (c == '\n') {
            ++ new_lines;
        }
    }
    printf("SPACES: %ld\nTABS: %ld\nNEW LINES: %ld\n", 
            spaces, tabs, new_lines);
    return 0;
}

