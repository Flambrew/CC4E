#include <stdio.h>

#define strcopy(s, t) while(*s++ = *t++);

int main() {
    char a[] = "hello ", b[] = "world!";
    char *s = a, *t = b;

    strcopy(s, t);

    while (*s) printf("%c", *s++);
    printf("\n");
}
