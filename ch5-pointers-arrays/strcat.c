#include <stdio.h>

int catstr(char *s, char *t) {
    while(*s) ++s;
    while (*s++ = *t++);
    return 0;
}

int main() {
    char a[] = "hello ", *s = a, b[] = "world!", *t = b;
    catstr(s, t);
    for (; *s; ++s) printf("%c", *s);
    printf("\n");
    return 0;
}
