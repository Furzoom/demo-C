#include <stdio.h>
#include <setjmp.h>

static jmp_buf buf;
static void fun(int val)
{
    switch (val)
    {
        case 0:
            longjmp(buf, 1);
            break;
        case 1:
            longjmp(buf, 2);
            break;
        case 2:
            longjmp(buf, 3);
            break;
        default:
            break;
    }
}

static void print_msg(int val)
{
    printf("value is %d\n", val);
}

int main()
{
    int value;
    value = setjmp(buf);
    print_msg(value);
    fun(value);
    return 0;
}

