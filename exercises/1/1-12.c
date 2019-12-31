#include <stdio.h>
#define ON  1
#define OFF 0

int main() {
	int ch, ch_count, new_line_toggle;
	ch_count = 0;
	new_line_toggle = OFF;	/* used to prevent printing multiple line breaks if there is more than one blank */

	printf("Value of EOF: %d\n", EOF);

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			printf("\nCharacter count: %d\n", ch_count);
			ch_count = 0;
		}

		else if (ch == '\t' || ch == ' ') {
			if (new_line_toggle == OFF) {
				printf("\n");
				new_line_toggle = ON;
			}
		}

		else {
			printf("%c", ch);
			++ch_count;
			new_line_toggle = OFF;
		}
	}
}

