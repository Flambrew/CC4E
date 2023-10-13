#include <stdio.h>

#define MAXLEN 20

main() {
    int len;
    char line[MAXLEN];

    while ((len = readline(line, MAXLEN)) > 0) {
        reverse(line, MAXLEN);
        printline(line, MAXLEN);
    }
}

readline(line, len) char line[]; int len; {
    int c, i;

    for (i = 0; i < len && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    for (c = i; c < len; ++c) {
        line[c] = 0x0;
    }

    if (i == len) {
        while ((c = getchar()) != EOF && c != '\n') {}
    }

    return i;
}

reverse(line, len) char line[]; int len; {
    int i, j;
    char temp[len];

    for (i = 0, j = len - 1; i < len; ++i, --j) {
        temp[j] = line[i];
    }

    for (i = 0; i < len; ++i) {
        line[i] = temp[i];
    }
}

printline(line, len) char line[]; int len; {
    int i;

    for (i = 0; i < len; ++i) {
        printf("%c", line[i]);
    }
    printf("\n");
}
