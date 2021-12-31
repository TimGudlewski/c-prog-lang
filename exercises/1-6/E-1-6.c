#include <stdio.h>
/* press ctrl+d to signal EOF */
/* verify that the expression getchar() != EOF is 0 or 1 */
void main(void)
{
  int c, d;
  c = getchar();
  d = c != EOF;
  printf("Val of exp before loop: %d\n", d);

  while (d) {
    putchar(c);
    c = getchar();
    d = c != EOF;
  }

  printf("Val of exp after loop: %d\n", d);
}
