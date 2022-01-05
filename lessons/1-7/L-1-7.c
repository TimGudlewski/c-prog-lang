#include <stdio.h>

int power(int m, int n);        /* function prototype: power is a function that expects two int arguments and returns an int
                                   parameter names are optional in a function prototype */

/* test power function */
int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
}
/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)      /* declare the parameter types and names, and the type of the result that the function returns
                                   parameter = a variable named in the parenthesized list in a function definition
                                   argument = the value used in a call of the function */
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
