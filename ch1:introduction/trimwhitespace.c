#include <stdio.h>

#define MAXLEN 20

char line[MAXLEN];

main() {
    int l, i;

    while ((l = nextlinelen()) > 0) {
        trimtrailingspace();

        if (line[0] != '\0') {
            printf("> ");
            for (i = 0; i < MAXLEN; ++i) {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

nextlinelen() {
    int c, i;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == EOF || c == '\n') {
        line[i] = c;
    }

    for (c = i; c < MAXLEN; ++c) {
        line[c] = 0x0;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    return i;
}

trimtrailingspace() {
    int c, i;

    for (i = MAXLEN - 1; i >= 0; --i) {
        if (line[i] == ' ' || line[i] == '\t') {
            line[i] = 0x0;
        } else if (line[i] != '\0') {
            break;
        }
    }
}
