#include <stdio.h> 

#define LENLIMIT 20
#define LINELIMIT 5

char lines[LINELIMIT][LENLIMIT];
int line = 0;

main() {
	while (getline() > 0 && line < LINELIMIT) {
		getline();
	}

	if (line < LINELIMIT) {
		int i;
		for (i = 0; i < LENLIMIT; ++i) {
			lines[line][i] = ' ';
		}
	}

	int i, c;
	for (i = 0; i < line; ++i) {
		for (c = 0; c < LENLIMIT; ++c) {
			printf("%c", lines[i][c]);
		}
		printf("\n");
	}
}

getline() {
	int c, i;

	for (i = 0; i < LENLIMIT - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		lines[line][i] = c;
	} 

	if (c == '\n') {
		lines[line][i++] = c;
	} else if (c != EOF) {
		while ((c = getchar()) != EOF && c != '\n') {
			++i;
		}
	}

	if (i >= LENLIMIT) {
		++line;
	}

	return i;
}
