#include <stdio.h>

int main() {
	int digit_count[10];
	int c, i, white_count, other_count;
	white_count = other_count = 0;
	
	for (i = 0; i <= 9; i++) {
		digit_count[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++digit_count[c - '0'];
		}

		else if (c == '\n' || c == '\t' || c == ' ') {
			++white_count;
		}

		else {
			++other_count;
		}
	}

	printf("DIGIT COUNT:\n");
	for (i = 0; i <= 9; i++) {
		printf("%d: %d\n", i, digit_count[i]);
	}

	printf("WHITESPACE COUNT: %d\n", white_count);
	printf("OTHER CHARACTER COUNT: %d\n", other_count);
}
