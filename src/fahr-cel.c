#include <stdio.h> 

#define LOWER 0
#define UPPER 300
#define STEP 20

#define C_TO_F 0
#define F_TO_C 1

void main() {
	float from, to;
	from = LOWER;

	int tableType;
	tableType = C_TO_F; 

	if (tableType) { /* ints are judged => nonzero values == true, zero == false*/
		printf("Fahrenheit to Celsius\n");
	} else { /* better to use #include<stdbool.h> for booleans now though */
		printf("Celsius to Fahrenheit\n");
	}

	while (from <= UPPER) {
		if (tableType) {
			to = (5.0 / 9.0) * (from - 32.0);
		} else {
			to = from * (9.0 / 5.0) + 32;
		}
		printf("%4.0f %6.1f\n", from, to);
		from = from + STEP;
	}
}
