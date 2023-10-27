#include <stdio.h>
#include "get-unget.c"

main() {
    double f;
    readfloat(&f);
    printf("%f\n", f);
}

readfloat(pf) double *pf; {
    int c, decimal;
    double power();
    *pf = 0;

    while ((c = getch()) == ' ' || c == '\n' || c == '\t');
    if (c == '+' || c == '-') *pf = c == '+' ? 0 : -0; else ungetch(c);
    for (;(c = getch()) >= '0' && c <= '9';)
        *pf = 10 * *pf + c - '0';

    if (c != '.') ungetch(c); else {
        for (decimal = 0; (c = getch()) >= '0' && c <= '9';)
            *pf += (double)(c - '0') / power(10, ++decimal);
        if (c != EOF) ungetch(c);
    }
}

double power(x, n) int x, n; {
    int i;
    double out = x;
    for (i = 1; i < n; ++i)
        out *= x;
    return out;
}

