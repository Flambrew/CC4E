#include <stdio.h>

int get_line(char *s) {
    for (char c; (c = getchar()) - '\n'; *s = c);

    return 0;
}

int main() {
    char a[15], *s = a;
    int i;

    printf("%ld\n", (long int)s);

    get_line(s);

    printf("%ld\n", (long int)s);

    for (i = 0; i < 15 && a[i] - '\n'; ++i)
        printf("%c", a[i]);
    printf("\n");

    return 0;
}
