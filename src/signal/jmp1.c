#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_code(void)
{
    longjmp(buf, 1);
}

int main()
{
    double dividend, divisor;
    printf("Input dividend: ");
    scanf("%lf", &dividend);
    printf("Input divisor: ");
    if (setjmp(buf) == 0)
    {
        scanf("%lf", &divisor);
        if (0 == divisor)
            error_code();
        printf("%lf / %lf = %lf\n", dividend, divisor, dividend / divisor);
    }
    else
    {
        printf("Error: divisor is zero\n");
    }
    return 0;
}

