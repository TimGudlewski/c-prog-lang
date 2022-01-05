#include <stdio.h>

/* press ctrl+d to signal EOF */
/* press ctrl+d twice if you've typed anything on the current line and haven't hit enter on it */
/* verify that the expression getchar() != EOF is 0 or 1 */

int main()
{
  int c, d;
  c = getchar();
  d = c != EOF;
  printf("Value of expression before loop: %d\n", d);

  while (d) {
    c = getchar();
    d = c != EOF;
  }

  printf("\nValue of expression after loop: %d\n", d);
}
