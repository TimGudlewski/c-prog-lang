/* remove trailing blanks and tabs from each line of input and delete entirely
 * blank lines */
/* completely blank lines either contain only the newline character or only
 * whitespace and the newline character */
/* output trailing whitespace lines and stripped lines to separate files so
 * running "diff" on them can verify */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* max length of a line */
#define MAXLINS 1000 /* max number of input lines */
#define TRUE 1
#define FALSE 0

char nblines[MAXLINS][MAXLINE]; /* all non-blank lines */
int getl(char tmpl[]);
void cpyl(int nbli, char tmpl[]);
char swichar(int ll);

int main() {
  extern char nblines[MAXLINS][MAXLINE];
  char templine[MAXLINE];
  int ll, pi, nbli; /* line length; print increment; non-blank line increment */
  nbli = 0;
  while (nbli < MAXLINS && (ll = getl(templine)) != 0) {
    if (ll > 1 || ll < 0) {
      templine[abs(ll)] = '\0';
      cpyl(nbli, templine);
      ++nbli;
    }
    if (ll < 0)
      break;
  }

  FILE *fp;
  char comment[50];

  fp = fopen("output_test.txt", "w");

  if (fp == NULL) {
    printf("file couldn't be opened\n");
    exit(1);
  }
  putchar(swichar(ll));
  for (pi = 0; pi < nbli; ++pi) {
    printf("%s", nblines[pi]);
    fputs(nblines[pi], fp);
  }
  putchar(swichar(ll));
  fclose(fp);
  return 0;
}

/***********************************************************************************/
/* read a line into templine, return length */
int getl(char templine[]) {
  int ci, c, eofr; /* character increment; character; end of file reached */
  int wsi, lcs;    /* whitespace increment; last character was a space */

  wsi = 0;
  eofr = lcs = FALSE;

  for (ci = 0; (c = getchar()) != EOF && c != '\n' && ci < MAXLINE - 1; ++ci) {
    if (c == ' ' || c == '\t') {
      lcs = TRUE;
      ++wsi;
    } else if (lcs == TRUE) {
      lcs = FALSE;
      wsi = 0;
    }
    templine[ci] = c;
  }

  ci -= wsi;
  if (c == '\n') {
    templine[ci] = c;
    ++ci;
  }
  if (c == EOF && ci > 0)
    ci = -ci;
  return ci;
}

/* copy templine into nblines at index nbli */
void cpyl(int nbli, char templine[]) {
  extern char nblines[MAXLINS][MAXLINE];
  int i;

  for (i = 0; (nblines[nbli][i] = templine[i]) != '\0'; ++i)
    ;
}

/* switch between \0 and \n based on whether line length is negative */
char swichar(int ll) {
  if (ll < 0)
    return '\n';
  else
    return '\0';
}
