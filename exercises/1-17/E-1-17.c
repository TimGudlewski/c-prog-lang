/* print all input lines longer than 80 characters */

#include <stdio.h>

#define MAXLINE 1000            /* max length of a line */
#define MAXLINS 1000            /* max number of >80 char long lines to save */
#define MINLINE 80
#define TRUE 1
#define FALSE 0

char llines[MAXLINS][MAXLINE];  /* an array of all the >80 char long lines */
int getl(int lt[]);
void cpyl(int lli, char tmpl[]);

int main()
{
    extern char llines[MAXLINS][MAXLINE];
    int lltl[] = {0, 0};        /* >80 char long lines increment; total lines increment */
    int i;                      /* printf increment */

    while (lltl[0] < MAXLINS && getl(lltl) != TRUE);

    printf("LINES LONGER THAN 80 CHARACTERS:\n");
    if (lltl[1] > 0) {
        for (i = 0; i < lltl[0]; ++i)
            printf("%s\n", llines[i]);
    }

    return 0;
}


/* getline: read a line into s, return length */
int getl(int lltl[])
{
    int i, c, eofr;
    char templine[MAXLINE];

    eofr = FALSE;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAXLINE - 1; ++i)
        templine[i] = c;

    if (c == EOF)
        eofr = TRUE;
    if (c == '\n') {
        templine[i] = c;
        ++i;
    }

    if (i > 0)
        ++lltl[1];
    if (i > 80) {
        templine[i] = '\0';
        cpyl(lltl[0], templine);
        ++lltl[0];
    }

    return eofr;
}


void cpyl(int llidx, char templine[]) /* params: line index of llines to copy to; char array to copy from */
{
    extern char llines[MAXLINS][MAXLINE];
    int i;

    i = 0;
    while ((llines[llidx][i] = templine[i]) != '\0')
        ++i;
}
