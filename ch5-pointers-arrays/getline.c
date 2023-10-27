#include <stdio.h>

int get_line(char *s) {
    while ((*s = getchar()) - EOF && *s++ - '\n');
    *s = '\0';
    return 0;
}

int main() {
    char a[15], *s = a;
    int i;

    get_line(s);

    for (i = 0; i < 15 && a[i] - '\n'; ++i)
        printf("%c", a[i]);
    printf("\n");

    return 0;
}
