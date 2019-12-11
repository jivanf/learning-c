#include <stdio.h>

int main() {
	int ch, count;
	count = 0;
	printf("Value of EOF is %d\n", EOF);
	while ((ch = getchar()) != EOF) {
		if (ch == 10) {
			printf("Character count: %d\n", count);
			count = 0;
		}

		else {
			printf("ASCII code of character %c: %d\n", ch, ch);
			printf("\n");
			++count;
		}
	}
}
