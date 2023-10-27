#include <stdio.h>

main() {
    printf("%d\n", rindex("hello world", 'o'));
}

rindex(s, t) char s[], t; {
    int i, n;
    for (i = n = 0; s[i] != '\0'; ++i) {
        if (s[i] == t) {
            n = i;
        }
    }
    return n;
}
