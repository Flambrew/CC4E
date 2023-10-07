#include <stdio.h>

main() {
	int c;

	while ((c = getchar()) != EOF) {
		printf("%c", lower(c));
	}
}

lower(c) int c; {
    return c >= 'A' && c <= 'Z' ? c + 0x20 : c;
}
