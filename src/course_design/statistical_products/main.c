/*
 * main.c - By furzoom @ Jan 08, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#define ITEM_NAME_LENGTH 10
#define SALE_NAME_LENGTH 10
#define BUFFER_LENGTH    128

typedef struct {
    unsigned int number;
    unsigned int year;
    unsigned int month;
    unsigned int day;
    double price;
    char item_name[ITEM_NAME_LENGTH];
    char sale_name[SALE_NAME_LENGTH];
} SaleTable;

static void test()
{
    char buff[BUFFER_LENGTH];
    const char* filename = "test.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "open file %s error\n", filename);
        exit(EXIT_FAILURE);
    }
    while (NULL != fgets(buff, BUFFER_LENGTH, fp))
    { 
        printf(buff);
    }
}

int main()
{
    test();    
    return 0;
}

