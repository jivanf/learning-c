#include <stdio.h>

#define MAXLINESIZE 1000  /* maximum amount of characters per line */
#define MAXTEXTSIZE 3000  /* maximum amount of characters in all lines */
#define MINPRINT    80	  /* minimum amount of characters the line needs to be printed */

int get_line(char line[], int max_len);
void copy(char origin[], char duplicate[]);
void concat(char base[], char new[]);

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

/* concat: add string 'new' to 'base' assuming 'base' is big enough */
void concat(char base[], char new[]) {
	int i, j, c;
	for (i = 0; base[i] != 0; ++i) {}
	for (j = 0; (c = new[j]) != 0; ++j) {
		printf("%c", base[i]);
		base[i] = c;
		++i;
	}
}
		
int main() {
	int line_size, max_line_size, c, incomplete;
	line_size = max_line_size = c = incomplete = 0;
	char current_line[MAXLINESIZE];
	char bigger_than_min_print[MAXTEXTSIZE] = {}; 
	bigger_than_min_print[MAXTEXTSIZE - 1] = '\0';
	char max_line[MAXLINESIZE];
	while ((line_size = get_line(current_line, MAXLINESIZE)) != 0) {
		if (current_line[line_size] != '\n') {
			while ((c = getchar()) != '\n' && c != EOF) {
				++line_size;
			}

			if (line_size > MAXLINESIZE) {
				printf("error: line is bigger than MAXLINESIZE (%d)\n", MAXLINESIZE);
				incomplete = 1;
			}

		}

		if (line_size > MINPRINT) {
			concat(bigger_than_min_print, current_line);
		}

		printf("length: %d\n", line_size);

		if (line_size > max_line_size) {
			max_line_size = line_size;
			copy(current_line, max_line);
		}
	}

	printf("longest line");
	if (incomplete) {
		printf(" (incomplete due to out of bounds input):\n");
	}

	else {
		printf(":\n");
	}

	printf("%s", max_line);

	if (incomplete) {
		printf("\n");
	}

	printf("length: %d\n\n", max_line_size);
	printf("longer than 80 characters:\n%s\n", bigger_than_min_print);
	
}


