#include <stdio.h>

int main() {
	int ch, ch_count, tab_count, backspace_count, backslash_count;

	ch_count = 0;
	tab_count = 0;
	backspace_count = 0;
	backslash_count = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			printf("Character count: %d\n", ch_count);
			ch_count = 0;
			tab_count = 0;
			backspace_count = 0;
			backslash_count = 0;
		}

		else if (ch == '\t') {
			printf("ASCII code of character \\t: %d\n", ch);
			printf("\n");
			++tab_count;
		}

		else if (ch == '\b') {
			printf("ASCII code of character \\b: %d\n", ch);
			printf("\n");
			++backspace_count;
		}

		else if (ch == '\\') {
			printf("ASCII code of character \\: %d\n", ch);
			printf("\n");
			++backslash_count;
		}

		else {
			printf("ASCII code of character %c: %d\n", ch, ch);
			printf("\n");
			++ch_count;
		}
	}
}

