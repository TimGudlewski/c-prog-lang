/* remove trailing blanks and tabs from each line of input and delete entirely blank lines */
/* completely blank lines either contain only the newline character or only whitespace and the newline character */
/* output trailing whitespace lines and stripped lines to separate files so running "diff" on them can verify */

#include <stdio.h>

#define MAXLINE 1000             /* max length of a line */
#define MAXLINS 1000             /* max number of input lines */
#define TRUE 1
#define FALSE 0

char nblines[MAXLINS][MAXLINE];  /* all non-blank lines */
void getl(int nber[], char tmpl[]);
void cpyl(int nbli, char tmpl[]);

int main()
{
    extern char nblines[MAXLINS][MAXLINE];
    char templine[MAXLINE];
    int pi, nbli;               /* non-blank line increment; print increment */
    nbli = 0;
    int nber[] = {FALSE, FALSE}; /* last line was non-blank; end of file reached */
    while (nbli < MAXLINS && nber[1] != TRUE) {
        getl(nber, templine);
        if (nber[0] == TRUE) {
            cpyl(nbli, templine);
            ++nbli;
        }
    }
    for (pi = 0; pi < nbli; ++pi)
        printf("Line %d:\n%s", pi, nblines[pi]);
    return 0;
}


/* getline: read a line into s, return length */
void getl(int nber[], char templine[])
{
    int ci, c, eofr;        /* character increment; character; end of file reached */
    int wsi, lcs;           /* whitespace increment; last character was a space */

    wsi = 0;
    eofr = lcs = FALSE;

    for (ci = 0; (c = getchar()) != EOF && c != '\n' && ci < MAXLINE - 1; ++ci) {
        if (c == ' ' || c == '\t') {
            lcs = TRUE;
            ++wsi;
        }
        else if (lcs == TRUE) {
            lcs = FALSE;
            wsi = 0;
        }
        templine[ci] = c;
    }
    if (c == EOF)
        nber[1] = TRUE;
    if (c == '\n') {
        templine[ci - wsi] = c;
        ++ci;
    }
    if (ci - wsi > 1) {
        nber[0] = TRUE;
        templine[ci - wsi] = '\0';
    }
    else
        nber[0] = FALSE;
}


void cpyl(int nbli, char templine[])
{
    extern char nblines[MAXLINS][MAXLINE];
    int i;

    for (i = 0; (nblines[nbli][i] = templine[i]) != '\0'; ++i);
}
