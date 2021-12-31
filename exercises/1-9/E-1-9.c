#include <stdio.h>

#define IN	1		/* inside a space sequence */
#define OUT	0		/* outside a space sequence */

/* replace each string of one or more blanks with a single blank */
void main()
{
  int c, spacestate;

  spacestate = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      spacestate = IN;
    else if (spacestate == IN) {
      putchar(' ');
      spacestate = OUT;
      putchar(c);
    }
    else
      putchar(c);
  }
}
