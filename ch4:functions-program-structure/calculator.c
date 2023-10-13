#include <stdio.h>

#define MAXOP 20
#define NUMBER '0'
#define TOOBIG '9'
#define VARIABLE 'a'

main() {
    int type;
    char s[MAXOP];
    double op2, atof(), pop(), push(), variable[27];

    while ((type = getop(s, MAXOP)) != EOF) {
        switch (type) {
            case NUMBER: push(atof(s)); break;
            case '+': push(pop() + pop()); break;
            case '*': push(pop() * pop()); break;
            case '-': op2 = pop(); push(pop() - op2); break;
            case '/':
                if ((op2 = pop()) == 0) printf("err: div by 0\n");
                else push(pop() / op2);
                break;
            case '%': op2 = pop(); push((int)pop() % (int)op2); break;
            case '=':
                op2 = pop();
                printf("\t%f\n", op2);
                variable[(int)pop() - VARIABLE + 1] = push(op2);
                break;
            case 'c': clear(); break;
            case 'e': pop(); break;
            case VARIABLE: push(s); break;
            case TOOBIG: printf("%.20s ... is too long\n", s); break;
            default: printf("err: undefined input: %c\n", type); break;
        }
    }
}

getop(s, lim) char s[]; int lim; {
    int i, c;

    while ((c = getch()) == ' ' || c == '\t' || c == '\n');
    if (c >= 'a' && c <= 'z') { s[0] = c; s[1] = '\0'; return VARIABLE; }
    if (c != '.' && (c < '0' || c > '9')) return c;

    s[0] = c;
    for (i = 1; (c = getchar()) >= '0' && c <= '9'; ++i) if (i < lim) s[i] = c;
    if (c == '.') {
        if (i < lim) s[i] = c;
        for (;(c = getchar()) >= '0' && c <= '9';) if (++i < lim) s[i] = c;
    }

    if (i < lim) {
        ungetch(c);
        s[i] = '\0';
        return NUMBER;
    } else while (c != '\n' && c != EOF) c = getchar();

    s[lim - 1] = '\0';
    return TOOBIG;
}
