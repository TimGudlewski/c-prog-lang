#include <stdio.h>

/* copy input to output: terse syntax */
void main(void)
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(c);
}
