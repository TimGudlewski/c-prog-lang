#include <stdio.h>
int main()
{
    int c = getchar();
    printf("\n%d\n", c);
    for (int i = 0; i < 256; ++i) {
        printf("  %d: ", i);
        putchar(i);
    }
    printf("\ntab:");
    int d = putchar('\t');
    printf("%d\n", d);

    printf("\nform feed:");
    d = putchar('\f');
    printf("%d\n", d);

    printf("\ncarriage return:");
    d = putchar('\r');
    printf("%d\n", d);
}
