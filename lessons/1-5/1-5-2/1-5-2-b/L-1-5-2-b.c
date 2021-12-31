#include <stdio.h>

/* count characters in input; version b */
void main()
{
  double nc;			/* double precision float */
  /* while and for test at the top of the loop, before proceeding with the body */
  for (nc = 0; getchar() != EOF; ++nc)
    ;			   /* null statement to satisfy the grammatical rules
			      of C that require that a for statement have a body */
  printf("%.0f\n", nc);		/* printf uses %f for both float and double */
  /* %.0f suppresses printing the decimal */
}
