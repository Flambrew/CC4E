#include <stdio.h>

main() {
	int c;

	while ((c = getchar()) != EOF) {
		printf("%c", lower(c));	
	}
}

lower(c) int c; {
	if (c >= 'A' && c <= 'Z') {
		return c + 0x20;
	} 
	return c;
}
