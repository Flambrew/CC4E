#include <stdio.h>

int htoi(char hex[], int len) {
    int i, out;

    for (i = out = 0; i < len; ++i) {
        out = out << 4;
        char c = hex[i];
        if (c >= 48 && c <= 57) out += c - 48;
        else if (c >= 65 && c <= 70) out += c - 55;
        else if (c >= 97 && c <= 102) out += c - 87;
        else return 0;
    }

    return out;
}

main() {
    unsigned int i, c, len;
    char in[8];

    while (c != EOF) {
        for (i = len = 0; i < 8 && (c = getchar()) != '\n' && c != EOF; ++i) {
            in[i] = c;
            ++len;
        }

        while (c != '\n' && c != EOF) c = getchar();
        printf("%d\n", htoi(in, len));
    }
}
