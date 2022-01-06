#include <stdio.h>

#define MAXLINE 1000

int getl(char line[], int maxline); /* there is already a function named getline in stdio? */
void copy(char to[], char from[]);

/* print the length of arbitrarily long input lines and AMAP of the text */
/* limit char arrays to length MAXLENGTH, but let i keep counting */
int main()
{
    long len;                   /* current line length */
    long top;                   /* top length seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];      /* longest line */

    top = 0;
    while ((len = getl(line, MAXLINE)) > 0) {
        if (len > top) {
            top = len;
            copy(longest, line);
        }
    }
    if (top > 0)                /* there was a line */
        printf("TOP LENGTH:\n%ld\nLONGEST LINE:\n%s\n", top, longest);  /* %s expects a string represented in the form of an array of characters
                                   terminated by the null character ('\0') */
    return 0;
}


/* getline: read a line into s, return length */
int getl(char s[], int lim)
{
    int c;
    long i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++ i)
        if (i < lim - 1)
            s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';                /* the null character, whose value is zero, marks the end of the string of characters */
    return i;
}


/* copy: copy 'from' into 'to'; to is big enough because of the limit test in getl */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
