#include <stdio.h>

#define TAB 4

int main() {
	int count, ch, i;
	count = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			count = 0;
			printf("\n");
		}

		else if (ch != '\t') {
			printf("%c", ch);
			if ((count += 1) == TAB) {
				count = 0;
			}
		}

		else {
			for (i = 0; i < (TAB - count); ++i) {
				printf(" ");
			}

			count = 0;
		}

	}

}	
