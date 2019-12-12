#include <stdio.h>

int main() {
	int ch, ch_count, tab_count, blank_count, newline_count;

	ch_count = 0;
	tab_count = 0;
	blank_count = 0;
	newline_count = 0;

	printf("Value of EOF: %d\n", EOF);
	while ((ch = getchar()) != EOF) {
		if (ch == '\t') {
			++tab_count;
		}

		else if (ch == ' ') {
			++blank_count;
		}

		else if (ch == '\n') {
			++newline_count;
			printf("Character count: %d\n", ch_count);
			printf("Tab count: %d\n", tab_count);
			printf("Blank count: %d\n", blank_count);
			printf("Newline count: %d\n", newline_count);
			ch_count = 0;
			tab_count = 0;
			blank_count = 0;
		}
		else {
			printf("ASCII code of character %c: %d\n", ch, ch);
			printf("\n");
			++ch_count;
		}
	}
}

