#include <stdio.h>

main() {
    char s[] = "hello world!";
    reverse(s, 12);
    printf("%s\n", s);
}

reverse(s, len) char s[]; int len; {
    reverseindex(s, len, 0);
}

reverseindex(s, len, index) char s[]; int len, index; {
    char c = s[index];
    s[index++] = s[--len];
    s[len] = c;

    if (index < len) reverseindex(s, len, index);
}
