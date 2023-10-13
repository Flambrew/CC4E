#include <stdio.h>

main() {
    char i, t[40];
    expandrange("-a-c--e-1-6B-E\0", t);
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
    int i, j, k;
    unsigned int a, b, c;
    for (i = j = a = b = c = 0; s[i] != '\0'; ++i) {
        c = b;
        b = a;
        a = s[i];
        if (i > 1 && b == '-' && c < a &&
                ((a - 48 < 10 && c - 48 < 10) ||
                 (a - 65 < 26 && c - 65 < 26) ||
                 (a - 97 < 26 && c - 97 < 26))) {
            t[j++] = '\b';
            t[j++] = '\b';
            for (k = c; k <= a; ++k) {
                t[j++] = k;
            }
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}
