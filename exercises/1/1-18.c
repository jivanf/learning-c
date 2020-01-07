#include <stdio.h>

#define MAXLINESIZE 1000  /* maximum amount of characters per line */
#define MAXTEXTSIZE 3000  /* maximum amount of characters in all lines */
#define MINPRINT    80	  /* minimum amount of characters the line needs to be printed */

int get_line(char line[], int max_len);
void copy(char origin[], char duplicate[]);

/* get_line: read a line into line, return its length in i */
int get_line(char line[], int max_size ) {
	int c, i;
	for (i = 0; i < MAXLINESIZE - 1 && ((c = getchar()) != EOF && c != '\n'); ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
	}

	line[i + 1] = '\0';
	return i;
}	

/* copy: copy a line from 'origin' to 'duplicate' */
void copy(char origin[], char duplicate[]) {
	int i = 0;
	while ((duplicate[i] = origin[i]) != '\0') {
		++i;
	}
}

int main() {
	int line_size, max_line_size, c, i;
	line_size = max_line_size = i = 0;

	char current_line[MAXLINESIZE];
	char max_line[MAXLINESIZE];
	char bigger_than_min_print[MAXTEXTSIZE] = {}; 

	bigger_than_min_print[MAXTEXTSIZE - 1] = '\0';
	while ((line_size = get_line(current_line, MAXLINESIZE)) != 0) {
		if (current_line[line_size] != '\n') {
			while ((c = getchar()) != '\n' && c != EOF) {
				++line_size;
			}

			if (line_size > MAXLINESIZE) {
				printf("error: line is bigger than MAXLINESIZE (%d)\n", MAXLINESIZE);
			}

		}

		printf("line with removed blanks:\n");
		for (i = 0; (c = current_line[i]) != '\0'; ++i) {
			if (c == ' ' || c == '\t' || c == '\n') {
				continue;
			}

			printf("%c", c);
		}

		printf("\n");
	}

}



