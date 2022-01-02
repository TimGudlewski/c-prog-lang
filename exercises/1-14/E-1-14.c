#include <stdio.h>

/* print a histogram of the frequencies of different characters in input */

#define SMAE 8                  /* smallest integer value corresponding to an escape character */
#define LARE 13                 /* largest integer value corresponding to an escape character */
#define SMAN 32                 /* smallest integer value corresponding to a non-escape character */
#define LARN 126                /* largest integer value corresponding to a non-escape character */
#define MAXE (LARE - SMAE + 1)  /* maximum number of different escape characters to count */
#define MAXN (LARN - SMAN + 1)  /* maximum number of different non-escape characters to count */
#define MAXC (MAXN + MAXE)      /* maximum total number of different characters to count */

int main()
{
    int c, i, j;                /* character, increment 1, increment 2 */
    int qchar[MAXC];            /* quantities of characters */
    int eclet[MAXE];            /* escape character letters */

    eclet[0] = 'b';             /* backspace (ctrl+h) */
    eclet[1] = 't';             /* tab */
    eclet[2] = 'n';             /* new line */
    eclet[3] = 'v';             /* vertical tab (ctrl+k) */
    eclet[4] = 'f';             /* form feed (ctrl+l) */
    eclet[5] = 'r';             /* carriage return (ctrl+m) run the following to enable:
                                   stty -icrnl */

    for (i = 0; i < MAXC; ++i)
        qchar[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= SMAN && c <= LARN)
            ++qchar[c - SMAN];
        else if (c >= SMAE && c <= LARE)
            ++qchar[c - SMAE + MAXN];
    }
    for (i = 0; i < MAXC; ++i) {
        if (i < MAXN) {
            putchar(' ');
            putchar(i + SMAN);
        }
        else {
            putchar('\\');
            putchar(eclet[i - MAXN]);
        }
        printf(": ");
        for (j = 0; j < qchar[i]; ++j)
            putchar('+');
        putchar('\n');
    }
}
