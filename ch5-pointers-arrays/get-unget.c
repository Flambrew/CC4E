#include <stdio.h>

#define BUFFERSIZE 100

static int buffer[BUFFERSIZE];
static int bufferposition = 0;

int getch() {
    return (bufferposition > 0) ? buffer[--bufferposition] : getchar();
}

void ungetch(c) char c; {
    if (bufferposition > BUFFERSIZE) printf("err: ungetch: too many chars");
    else buffer[bufferposition++] = c;
}

void ungets(s, len) int s[], len; {
    int i;

    for (i = 0; i < len; ++i) {
        putchar(s[i]);
    }
}
