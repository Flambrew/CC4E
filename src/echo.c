#include <stdio.h>

main() {
	unsigned int c, n = 0, l = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') { ++l; }
		++n;
		if (c == '\t') { c = '>'; }
		if (c == '\n') { c = '<'; }
  		putchar(c);
	}
	printf("%d characters echoed (%d lines)\n", n, l);
}

