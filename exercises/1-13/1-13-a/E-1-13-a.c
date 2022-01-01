#include <stdio.h>

#define IN		1               /* inside a word */
#define OUT	0               /* outside a word */

/* Print a horizontal histogram of the lengths of words in input */

int main()
{
    int c, i, j, wcc;           /* character, increment 1, increment 2, word count, word character count */
    int wstate, cstate;         /* word state, character state */
    int lword[20];              /* assuming there are no words in the input longer than 20 characters */
    int nwchar[11];             /* non-word characters */

    for (i = 0; i < 20; ++i)
        lword[i] = 0;

    nwchar[0] = ' ';
    nwchar[1] = '\t';
    nwchar[2] = '\n';
    nwchar[3] = ',';
    nwchar[4] = '.';
    nwchar[5] = ':';
    nwchar[6] = ';';
    nwchar[7] = '!';
    nwchar[8] = '(';
    nwchar[9] = ')';
    nwchar[10] = '?';

    wstate = OUT;
    wcc = 0;
    while((c = getchar()) != EOF) {
        cstate = OUT;
        for (i = 0; i < 11; ++i) {
            if (c == nwchar[i]) {
                cstate = IN;
                break;
            }
        }
        if (cstate == IN) {
            if (wstate == IN) {
                ++lword[wcc];
                wcc = 0;
            }
            wstate = OUT;
        }
        else {
            ++wcc;
            wstate = IN;
        }
    }

    printf("word lengths:\n");
    for (i = 0; i < 20; ++i) {
        printf("%4d: ", i);
        for (j = 0; j < lword[i]; ++j)
            printf("+");
        printf("\n");
    }
}
