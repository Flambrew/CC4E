#include <stdio.h>

main() {
    char i, t[15];
    expand("wo\tld\n\0", t);
    for (i = 0; t[i] != '\0'; ++i) {
        printf("%c", t[i]);
    }
    printf("\n");
}

expand(s, t) char s[], t[]; {
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

expandrange(s, t) char s[], t[]; {
    int i, j;
    char a, b, c;
    for (i = j = 0; s[i] != '\0'; ++i) {
        c = b;
        b = a;
        a = s[i];
        if (b == '-') {
            if (a - 48 < 10 && c - 48 < 10 && a < c
        } else {
            t[j++] = s[i];
        }

