#include <stdio.h>

/* replace each tab, backspace, backslash with \t, \b, \\ */

void main()
{
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')		/* type Ctrl+h in bash to enter this character */
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
}
