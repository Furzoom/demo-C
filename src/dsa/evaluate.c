/* 
 * evaluate.c - eavluate a expression
 * Copyright (C) 2013-2015 FURZOOM.COM
 *
 * @file      evaluate.c
 * @brief     eavluate a expression
 * @details   eavluate a expression
 * @author    Yan Ma
 * @version   1.0
 * @date      2015-12
 * @history
 * @website  http://furzoom.com/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* macro */
#define OPR_STACK_SIZE 100
#define OPD_STACK_SIZE 100
#define SIGN_NUM 8

/* constant */
typedef enum STACK_TYPE {OPR, OPD} stack_type;
typedef enum OPERATOR {ADD, SUB, MUL, DIV, POW, L_P, R_P, EOE} Operator;

/* data structure */
typedef struct OPR_STACK {
    int size;
    int capacity;
    char data[OPR_STACK_SIZE];
} opr_stack;

typedef struct OPD_STACK {
    int size;
    int capacity;
    double data[OPD_STACK_SIZE];
} opd_stack;


/* stack */
void *init_stack(stack_type type);
void free_stack(void *s);
int push(void *s, stack_type type, void *e);
void *pop(void *s, stack_type type);
void *top(void *s, stack_type type);
int empty(void *s, stack_type type);
int size(void *s, stack_type type);

double evaluate(char *expr);
double readnum(const char *p, int *pos);
char cmp_opr(char cur, char top);
double cal(double d1, double d2, char op);
char *trim(char *s);

int main(int argc, char *argv[])
{
    char input[OPD_STACK_SIZE * 10];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [expression]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strncpy (input, argv[1], OPD_STACK_SIZE * 10 - 1);
    double result = evaluate(input);
    printf("%lf\n", result);

    return 0;
}

void *init_stack(stack_type type)
{
    void *val = NULL;
    switch (type)
    {
        case OPR:
        {
            opr_stack *s = (opr_stack *)malloc(sizeof(opr_stack));
            if (s == NULL)
                break;
            s->size = 0;
            s->capacity = OPR_STACK_SIZE;
            val = s;
            break;
        }
        case OPD:
        {
            opd_stack *s = (opd_stack *)malloc(sizeof(opd_stack));
            if (s == NULL)
                break;
            s->size = 0;
            s->capacity = OPD_STACK_SIZE;
            val = s;
            break;
        }
        default:
            exit(EXIT_FAILURE);
            break;
    }
    return val;
}

void free_stack(void *s)
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

int push(void *s, stack_type type, void *e)
{
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        switch (type) 
        {
            case OPR:
            {
                opr_stack *ss = (opr_stack *)s;
                char *data = (char *)e;
                if (ss->size >= ss->capacity)
                {
                    return 2;
                }
                else
                {
                    ss->data[ss->size] = *data;
                    ss->size ++;
                    return 0;
                }
                break;
            }
            case OPD:
            {
                opd_stack *ss = (opd_stack *)s;
                double *data = (double *)e;
                if (ss->size >= ss->capacity)
                {
                    return 2;
                }
                else
                {
                    ss->data[ss->size] = *data;
                    ss->size ++;
                    return 0;
                }
                break;
            }
            default:
                exit(EXIT_FAILURE);
                break;
        }
        return 3;
    }
}

void *pop(void *s, stack_type type)
{
    void *val;
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        switch (type)
        {
            case OPR:
            {
                opr_stack *ss = (opr_stack *)s;
                if (ss->size <= 0)
                {
                    return NULL;
                }
                else
                {
                    val = (void *)&ss->data[ss->size - 1];
                    ss->size --;
                }
                break;
            }
            case OPD:
            {
                opd_stack *ss = (opd_stack *)s;
                if (ss->size <= 0)
                {
                    return NULL;
                }
                else
                {
                    val = (void *)&ss->data[ss->size - 1];
                    ss->size --;
                }
                break;
            }
            default:
                return NULL;
        }
        return val;
    }
}

void *top(void *s, stack_type type)
{ 
    void *val;
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        switch (type)
        {
            case OPR:
            {
                opr_stack *ss = (opr_stack *)s;
                if (ss->size <= 0)
                {
                    return NULL;
                }
                else
                {
                    val = (void *)&ss->data[ss->size - 1];
                }
                break;
            }
            case OPD:
            {
                opd_stack *ss = (opd_stack *)s;
                if (ss->size <= 0)
                {
                    return NULL;
                }
                else
                {
                    val = (void *)&ss->data[ss->size - 1];
                }
                break;
            }
            default:
                return NULL;
        }
        return val;
    }
}

int empty(void *s, stack_type type)
{
    if (s == NULL)
    {
        return 1;
    } 
    else
    {
        switch (type)
        {
            case OPR:
            {
                opr_stack *ss = (opr_stack *)s;
                if (ss->size == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                break;
            }
            case OPD:
            {
                opd_stack *ss = (opd_stack *)s;
                if (ss->size == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
                break;
            }
            default:
                exit(EXIT_FAILURE);
                break;
        }
    }
}

int size(void *s, stack_type type)
{
    if (s == NULL)
    {
        return -1;
    }
    else
    {
        switch (type)
        {
            case OPR:
            {
                opr_stack *ss = (opr_stack *)s;
                return ss->size;
                break;
            }
            case OPD:
            {
                opd_stack *ss = (opd_stack *)s;
                return ss->size;
                break;
            }
            default:
                exit(EXIT_FAILURE);
                break;
        }
    }
}

double evaluate(char *expr)
{
    if (expr == NULL)
    {
        return 0.0;
    }

    trim(expr);

    int index = 0;
    double num;
    char op;
    opr_stack *opr;
    opd_stack *opd;

    opr = (opr_stack *)init_stack(OPR);
    opd = (opd_stack *)init_stack(OPD);

    op = '\0';
    push(opr, OPR, &op);

    while (!empty(opr, OPR))
    {
        if (isdigit(expr[index]))
        {
            num = readnum(expr, &index);
            if ( 0 != push(opd, OPD, &num))
            {
                fprintf(stderr, "Error push\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            switch (cmp_opr(expr[index], *(char *)top(opr, OPR)))
            {
                case '=':
                    pop(opr, OPR);
                    index++;    
                    break;
                case '>':
                    push(opr, OPR, &expr[index]);
                    index++;    
                    break;
                case '<':
                {
                    double opd1, opd2, val;
                    char op;
                    if (size(opd, OPD) < 2)
                    {
                        fprintf(stderr, "Error expression.\n");
                        exit(EXIT_FAILURE);
                    }
                    opd2 = *(double *)pop(opd, OPD);
                    opd1 = *(double *)pop(opd, OPD);
                    op = *(char *)pop(opr, OPR);
                    val = cal(opd1, opd2, op);
                    push(opd, OPD, &val);
                }
                    break;
                default:
                    fprintf(stderr, "Error expression.\n");
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }

    if (!empty(opd, OPD))
    {
        double val = *(double *)pop(opd, OPD);
        free_stack(opr);
        free_stack(opd);
        return val;
    }
    else
    { 
        free_stack(opr);
        free_stack(opd);
        fprintf(stderr, "Error expression.\n");
        exit(EXIT_FAILURE);
    }
}

double readnum(const char *p, int *pos)
{
    double result;
    sscanf(p + *pos, "%lf", &result);
    int flag = 0;
    while (p[*pos] && (isdigit(p[*pos]) || (flag == 0 && p[*pos] == '.')))
    {
        if (p[*pos] == '.')
        {
            flag = 1;
        }
        (*pos) ++;
    }
    return result;
}

char cmp_opr(char cur, char top)
{
    static char pri[SIGN_NUM][SIGN_NUM] = {
    /* top    +    -    *    /    ^    (    )    \0  */
    /* cur */
    /* + */ {'<', '<', '<', '<', '<', '>', ' ', '>'},
    /* - */ {'<', '<', '<', '<', '<', '>', ' ', '>'},
    /* * */ {'>', '>', '<', '<', '<', '>', ' ', '>'},
    /* / */ {'>', '>', '<', '<', '<', '>', ' ', '>'},
    /* ^ */ {'>', '>', '>', '>', '<', '>', ' ', '>'},
    /* ( */ {'>', '>', '>', '>', '>', '>', ' ', '>'},
    /* ) */ {'<', '<', '<', '<', '<', '=', ' ', ' '},
    /* \0 */{'<', '<', '<', '<', '<', '<', ' ', '='}
    };

    Operator o1, o2;
    switch (cur)
    {
        case '+':
            o1 = ADD;
            break;
        case '-':
            o1 = SUB;
            break;
        case '*':
            o1 = MUL;
            break;
        case '/':
            o1 = DIV;
            break;
        case '^':
            o1 = POW;
            break;
        case '(':
            o1 = L_P;
            break;
        case ')':
            o1 = R_P;
            break;
        case '\0':
            o1 = EOE;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
    }

    switch (top)
    {
        case '+':
            o2 = ADD;
            break;
        case '-':
            o2 = SUB;
            break;
        case '*':
            o2 = MUL;
            break;
        case '/':
            o2 = DIV;
            break;
        case '^':
            o2 = POW;
            break;
        case '(':
            o2 = L_P;
            break;
        case ')':
            o2 = R_P;
            break;
        case '\0':
            o2 = EOE;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
    }
    return pri[o1][o2];

}

double cal(double d1, double d2, char op)
{
    switch (op)
    {
        case '+':
            return d1 + d2;
            break;
        case '-':
            return d1 - d2;
            break;
        case '*':
            return d1 * d2;
            break;
        case '/':
            return d1 / d2;
            break;
        case '^':
            return pow(d1, d2);
            break;
        default:
            fprintf(stderr, "Operator error!\n");
            exit(EXIT_FAILURE);
            break;
    }
}

char *trim(char *s)
{
    char *cur, *p;
    cur = p = s;
    while (*p)
    {
        if (*p != ' ' && *p != '\t')
        {
            *cur++ = *p++;
        }
        else
        {
            p++;
        }
    }
    *cur = *p;
    return s;
}

