#include <stdio.h>

main() {
	unsigned int c, n = 0, l = 0, w = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') { ++l; ++w; }
		if (c == '\t') { c = '>'; ++w; }
		if (c == ' ') { ++w; }
  		putchar(c);
		++n;
	}
	printf("%d characters echoed (%d word%s, %d line%s)\n", 
			n, w, w == 1 ? "" : "s", l, l == 1 ? "" : "s");
}

