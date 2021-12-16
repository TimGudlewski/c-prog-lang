/* print Fahrenheit-Celsius table in reverse order using symbolic constants */

#include <stdio.h>

#define	LOWER	0		/* lower limit of table */
#define	UPPER	300		/* upper limit of table */
#define	STEP	20		/* step size */

void main(void)
{
  int fahr;

  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32)); /* In any context where it is permissible to use the value of a variable of some type, you can use a more complicated
							expression of that type */
}
