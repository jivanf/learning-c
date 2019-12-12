#include <stdio.h>

int main() {
	int ch, ch_count, blank_count;

	ch_count = 0;
	blank_count = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			++blank_count;
			if (blank_count > 1) {
				continue;
			}

		}

		if (ch != '\n') {
			printf("ASCII code of character %c: %d\n", ch, ch);
			printf("\n");
			++ch_count;
		}

		else {
			printf("Character count: %d\n", ch_count);
			if (blank_count > 1) {
				printf("Replaced %d blanks\n", blank_count - 1);
			}
			ch_count = 0;
			blank_count = 0;
		}
	}
}

