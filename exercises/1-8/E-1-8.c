#include <stdio.h>

/* count blanks, tabs, newlines */

void main()
{
  int b, t, nl, c;

  b = t = nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++b;
    if (c == '\t')
      ++t;
    if (c == '\n')
      ++nl;
  }
  printf("\nblanks: %d, tabs: %d, newlines: %d\n", b, t, nl);
}
