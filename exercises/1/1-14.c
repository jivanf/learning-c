#include <stdio.h>

int main() {
	int i, j, ch, most_repeated_char;
	int chars[93] = {};	/* non-space ASCII characters */
	most_repeated_char = 0;

	while ((ch = getchar()) != EOF) {
		if (ch > 32 && ch < 127) {
			++chars[ch - 33];
		}

	}

	for (i = 0; i < 93; i++) {
		if (most_repeated_char == 0) {
			most_repeated_char = chars[i];
		}

		else {
			if (chars[i] > most_repeated_char) {
				most_repeated_char = chars[i];
			}
		}
	}

	for (i = 0; i < 93; i++) {
		printf("%c │  ", i + 33);
		for (j = 0; j < chars[i]; j++) {
			printf("*  ");
		}
		printf("\n");
	}

	printf("  └");

	for (i = 0; i < most_repeated_char; i++) {
		printf("───");
	}

	printf("\n");
	printf("   ");

	for (i = 1; i <= most_repeated_char; i++) {
		printf("%3d", i);
	}

	printf("\n");
}
