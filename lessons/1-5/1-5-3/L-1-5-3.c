#include <stdio.h>

/* count lines in input */
void main()
{
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')		/* A character written in single quotes represents an integer value
				  equal to the numerical value of the character in the machine's character set */
      ++nl;
  printf("%d\n", nl);
}
