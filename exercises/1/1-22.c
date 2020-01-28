#include <stdio.h>

#define MAX_INPUT 5000
#define MAX_LINE  6

/* get_line: read a line into line */
void get_line(char line[], int max) {
	int ch, i;
	i = 0;
	while (i < max - 1 && ((ch = getchar()) != '\n' && ch != EOF)) {
		line[i] = ch;
		++i;
	}

	if (ch == '\n') {
		line[i] = '\n';
	}

	line[i + 1] = '\0';

}

/* fold_line: fold a line into two or more lines */
void fold_line(char line[], int max) {
	int blank_pos, ch, i;
	blank_pos = 0;
	for (i = 0; (ch = line[i]) != '\n' && ch != '\0'; ++i) {
		/* modulo operation to not have a separate counter */
		if (i % max == max - 1) {
			if (blank_pos != 0) {
				line[blank_pos] = '\n';
				blank_pos = 0;
			}

			else {
				/* loop through line until space is found if line is too long */
				for (; (ch = line[i]) != ' ' && ch != '\n' && ch != '\0'; ++i) {}

				if (ch == '\n' || ch == '\0') {
					break;
				}

				line[i] = '\n';
			}

		}
		if (ch == ' ' || ch == '\t') {
			blank_pos = i;
		}
	}
}

int main() {
	char line[MAX_INPUT];
	int line_size;
	get_line(line, MAX_INPUT);
	printf("\noriginal line: \n%s\n", line);
	fold_line(line, MAX_LINE);
	printf("folded line:\n%s", line);
}
