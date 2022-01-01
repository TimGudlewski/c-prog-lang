#include <stdio.h>

#define IN		1               /* inside a word */
#define OUT		0               /* outside a word */
#define MAXL	20              /* max length of word measurements */

/* Print a vertical histogram of the lengths of words in input */

int main()
{
    int c, i, j, wcc, topl;     /* character, increment 1, increment 2, word character count, most common word length */
    int wstate, cstate;         /* word state, character state */
    int lword[MAXL];            /* word lengths */
    int nwchar[11];             /* non-word characters */

    for (i = 0; i < MAXL; ++i)
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
                ++lword[wcc - 1];
                wcc = 0;
            }
            wstate = OUT;
        }
        else {
            ++wcc;
            wstate = IN;
        }
    }
    /* find most common word length */
    topl = lword[0];
    for (i = 1; i < MAXL; ++i) {
        if (lword[i] > topl)
            topl = lword[i];
    }
    /* print histogram */
    for (j = topl; j > 0; --j) {
        for (i = 0; i < MAXL; ++i) {
            if (lword[i] < j)
                printf("    ");
            else
                printf("   +");
        }
        printf("\n");
    }
    for (i = 0; i < MAXL; ++i) {
        printf("%4d", i + 1);
    }
    printf("\n");
}
