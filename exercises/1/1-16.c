#include <stdio.h>

#define MAXSIZE 1000

int get_line(char line[], int max_len);
void copy(char origin[], char duplicate[]);

/* getline: read a line into line, return its length in i */
int get_line(char line[], int max_size ) {
	int c, i;
	for (i = 0; i < MAXSIZE - 1 && ((c = getchar()) != EOF && c != '\n'); ++i) {
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
	int line_size, max_line_size, c, incomplete;
	line_size = max_line_size = c = incomplete = 0;
	char current_line[MAXSIZE];
	char max_line[MAXSIZE];
	while ((line_size = get_line(current_line, MAXSIZE)) != 0) {
		if (current_line[line_size] != '\n') {
			while ((c = getchar()) != '\n' && c != EOF) {
				++line_size;
			}

			if (line_size > MAXSIZE) {
				printf("error: line is bigger than MAXSIZE (%d)\n", MAXSIZE);
				incomplete = 1;
			}
		}

		printf("length: %d\n", line_size);

		if (line_size > max_line_size) {
			max_line_size = line_size;
			copy(current_line, max_line);
		}
	}

	printf("longest line");
	if (incomplete) {
		printf(" (incomplete due to out of bounds input): ");
	}

	else {
		printf(": ");
	}

	printf("%s\n", max_line);
	printf("length: %d\n", max_line_size);
}

