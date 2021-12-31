#include <stdio.h>
/* press ctrl+d to signal EOF */
/* print the value of EOF */
void main(void)
{
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  printf("Val of EOF: %d\n", EOF);
}
