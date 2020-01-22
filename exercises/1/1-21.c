#include <stdio.h>

#define TAB 8 /* set this to your system's tab */

int main() {
	int col, blank_count, ch;
	blank_count = 0;
	col = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			blank_count += 1;
		}

		else if (ch == '\n') {
			col = 0;
			printf("\n");
			continue;
		}

		else {
			if (blank_count > 0) {
				int tab_len, filled_blanks;
				filled_blanks = 0;

				while (1) {
					tab_len = TAB - (col % TAB);

					if ((filled_blanks + tab_len) > blank_count) {
						break;
					}

					filled_blanks += tab_len;
					col += tab_len;
					printf("\t");
				}

				/* add blanks if the tabs didn't fill all the spaces */
				if (filled_blanks != blank_count) {
					++filled_blanks;
					while (filled_blanks <= blank_count) {
						printf(" ");
						++filled_blanks;
						++col;
					}
				}

				blank_count = 0;
			}

			++col;
			printf("%c", ch);
		}

	}
}
