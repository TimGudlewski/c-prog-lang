#include <stdio.h>

/* print Fahrenheit-Celsius table in reverse order */
void main(void)
{
  int fahr;

  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32)); /* In any context where it is permissible to use the value of a variable of some type, you can use a more complicated
							expression of that type */
}
