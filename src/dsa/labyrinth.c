/* 
 * labyrinth.c - labyrinth
 * Copyright (C) 2013-2015 FURZOOM.COM
 *
 * @file      labyrinth.c
 * @brief     labyrinth
 * @details   labyrinth
 * @author    Yan Ma
 * @version   1.0
 * @date      2015-12
 * @history
 * @website   http://furzoom.com/
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constant */
typedef enum {AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum {UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;

/* macro */
#define nextESWN(eswn) ((ESWN)(eswn + 1))
#define LABY_MAX 24
#define STACK_MAX 100

/* data structure */
typedef struct CELL {
    int x, y;
    Status status;
    ESWN incoming;
    ESWN outgoing;
} Cell;

typedef struct STACK {
    int size;
    int capacity;
    Cell *data[STACK_MAX];
} stack;

/* global varibale */
Cell laby[LABY_MAX][LABY_MAX];
stack *path;

/* functions */
Cell *neighbor(Cell *cell);
Cell *advance(Cell *cell);
stack *init_stack();
void free_stack(stack *s);
int push(stack *s, Cell *c);
Cell *pop(stack *s);
Cell *top(stack *s);
int empty(stack *s);
int labyrinth(Cell la[][LABY_MAX], Cell *s, Cell *e);
void read_map(const char* file);
void print_map(Cell la[][LABY_MAX]);

/* main */
int main()
{
    char *mapname = "map.txt";
    if ((path = init_stack()) == NULL)
    {
        fprintf(stderr, "init stack null\n");
    }
    read_map(mapname);
    labyrinth(laby, &laby[4][9], &laby[4][1]);
    
    free_stack(path);
    return 0;
}



Cell *neighbor(Cell *cell)
{
    switch (cell->outgoing)
    {
        case EAST:
            return &laby[cell->x - 1][cell->y];
        case SOUTH:
            return &laby[cell->x][cell->y - 1];
        case WEST:
            return &laby[cell->x - 1][cell->y - 2];
        case NORTH:
            return &laby[cell->x - 2][cell->y - 1];
        default:
            fprintf(stderr, "neighbor error\n");
            exit(EXIT_FAILURE);
    }
}

Cell *advance(Cell *cell)
{
    Cell *next;
    switch (cell->outgoing)
    {
        case EAST:
            next = &laby[cell->x - 1][cell->y];
            next->incoming = WEST;
            break;
        case SOUTH:
            next = &laby[cell->x][cell->y - 1];
            next->incoming = NORTH;
            break;
        case WEST:
            next = &laby[cell->x - 1][cell->y - 2];
            next->incoming = EAST;
            break;
        case NORTH:
            next = &laby[cell->x - 2][cell->y - 1];
            next->incoming = SOUTH;
            break;
        default:
            fprintf(stderr, "advance error\n");
            exit(EXIT_FAILURE);
    }
    return next;
}

stack *init_stack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        s->size = 0;
        s->capacity = STACK_MAX;
        return s;
    }
}

void free_stack(stack *s)
{
    if (s == NULL)
    {
        return;
    }
    else
    {
        free(s);
    }
}

int push(stack *s, Cell *c)
{
    if (s == NULL)
    {
        return 1;
    }
    else if (s->size >= s->capacity)
    {
        return 2;
    }
    else if (c == NULL)
    {
        return 3;
    }
    else
    {
        s->data[s->size ++] = c;
        return 0;
    }
}

Cell *pop(stack *s)
{
    if (s == NULL || s->size == 0)
    {
        return NULL;
    }
    else
    {
        return s->data[--(s->size)];
    }
}

Cell *top(stack *s)
{
    if (s == NULL || s->size == 0)
    {
        return NULL;
    }
    else
    {
        return s->data[s->size - 1];
    }
}

int empty(stack *s)
{
    if (s == NULL || s->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int labyrinth(Cell la[][LABY_MAX], Cell *s, Cell *e)
{
    int test;
    Cell *c;
    if (s->status != AVAILABLE || e->status != AVAILABLE)
        return 0;
    s->status = ROUTE;
    s->incoming = UNKNOWN;
    if (0 != (test = push(path, s)))
    {
        fprintf(stderr, "push error: %d\n", test);
    }

    do
    {
        c = top(path);
        if (c->x == e->x && c->y == e->y)
            return 1;
        while ((c->outgoing = nextESWN(c->outgoing)) < NO_WAY)
        {
            if (neighbor(c)->status == AVAILABLE)
                break;
        }
        if (c->outgoing >= NO_WAY)
        {
            c->status = BACKTRACKED;
            c = pop(path);
        }
        else
        {
            if (0 != (test = push(path, c = advance(c))))
            {
                fprintf(stderr, "push error: %d\n", test);
            }
            c->outgoing = UNKNOWN;
            c->status = ROUTE;
        }
        print_map(la);
    } while (!empty(path));
    return 0;
}

void read_map(const char* file)
{
    int i, m, n, col, size;
    char buff[512];
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open file %s\n", file);
        exit(EXIT_FAILURE);
    }
    size = fread(buff, 1, 512, fp);
    fclose(fp);

    memset(laby, 0, sizeof(laby));

    m = n = col = 0;
    for (i = 0; i < size; i ++)
    {
        if (buff[i] == '\n')
        {
            m ++;
            n = 0;
        }
        else if (buff[i] == '0')
        {
            laby[m][n].x = m + 1;
            laby[m][n].y = n + 1;
            laby[m][n].status = AVAILABLE;
            n ++;
        }
        else if (buff[i] == '1')
        {
            laby[m][n].x = m + 1;
            laby[m][n].y = n + 1;
            laby[m][n].status = WALL;
            n ++;
        }
    }
    print_map(laby);
}

void print_map(Cell la[][LABY_MAX])
{
    int i, j;
    for (i = 0; i < LABY_MAX; i ++)
    {
        if (la[i][0].status != WALL)
            break;
        for (j = 0; j < LABY_MAX; j ++)
        {
            if (la[i][j].status == AVAILABLE)
                printf("  ");
            else if (la[i][j].status == WALL)
                printf("■");
            else if (la[i][j].status == ROUTE)
                printf("●");
            else if (la[i][j].status == BACKTRACKED)
                printf("○");
        }
        printf("\n");
    }
    printf("\n");
}

