#include <stdio.h>
#define MAXLINE 1000            /* maximum input line size */

int newgetline(char line[], int maxline); /* there is already a function named getline in stdio? */
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                    /* current line length */
    int max;                    /* maximum length seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];      /* longest line */

    max = 0;
    while ((len = newgetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)                /* there was a line */
        printf("%s", longest);  /* %s expects a string represented in the form of an array of characters
                                   terminated by the null character ('\0') */
    return 0;
}


/* getline: read a line into s, return length */
int newgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++ i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';                /* the null character, whose value is zero, marks the end of the string of characters */
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
