#include <stdio.h>

#define LINEWIDTH 80
#define TABWIDTH 4

main() {
    int c, i, tabct, string, len, paren;

    tabct = 0, string = 0, len = 0, paren = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '{':
                len = wrap(len, 2);
                printf(" %c\n", c);
                len = 0;
                for (i = 0, ++tabct; i < tabct * TABWIDTH; ++i) { printf(" "); }
                len = wrap(len, tabct * TABWIDTH);
                break;

            case '}':
                --tabct;
                --len;
                for (i = 0; i < TABWIDTH; ++i) {
                    printf("\b");
                }
            case ';':
                if (paren) {
                    len = wrap(len, 1);
                    printf("%c", c);
                } else {
                    len = wrap(len, 2);
                    printf("%c\n", c);
                    len = 0;
                    for (i = 0; i < tabct * TABWIDTH; ++i) { printf(" "); }
                    len = wrap(len, tabct * TABWIDTH);
                }
                break;

            case '\t':
                if (!string) {
                    len = wrap(len, 4);
                    printf("\\t");
                }
                break;

            case '"':
                string = -string + 1;
                len = wrap(len, 1);
                printf("\"");
                break;

            case ' ':
                if (!string) {
                    break;
                }
                paren -= 1;
            case '(':
                paren += 2;
            case ')':
                paren -= 1;
            default:
                len = wrap(len, 1);
                printf("%c", c);
        }
    }
}

wrap(len, n) int len, n; {
    if ((len += n) >= LINEWIDTH) {
        printf("\n");
        len = n;
    }
    return len;
}
