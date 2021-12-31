#include <stdio.h>

/* count characters in input: version a */
void main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
}
