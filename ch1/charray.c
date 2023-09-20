#include <stdio.h> 

#define MAXLEN 10

main() {
	int len, max;
	char line[MAXLEN], save[MAXLEN];

	max = 0;
	while ((len = getlen(line, MAXLEN)) > 0) {
		if (len > max) {
			max = len;
			copy(line, save);
		}
	}

	if (max > 0) {
		printf("%s", save);
	}
}

getlen(s, lim) char s[]; int lim; {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	} else if (c != EOF) {
		while ((c = getchar()) != EOF && c != '\n') {
			++i;
		}
	}

	s[i] = '\0';
	return i;
}

copy(s1, s2) char s1[], s2[]; {
	int i; 

	i = 0;
	while ((s2[i] = s1[i]) != '\0') {
		++i;
	}
}
