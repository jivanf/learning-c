#include <stdio.h>

#define MAXLINESIZE 1000  /* maximum amount of characters per line */

int get_line(char line[], int max_len);
void copy(char origin[], char duplicate[]);
void reverse(char s[]);

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

void reverse(char s[]) {
	int len, i, c;
	i = 0;
	for (len = 0; (c = s[len]) != '\0' && c != '\n'; ++len) {}

	if (c == '\n') {
		len--;
	}

	char buffer[len];
	for (; len >= 0; --len) {
		buffer[i] = s[len];
		++i;
	}
	buffer[i] = '\0';	
	copy(buffer, s);

}

int main() {
	int line_size, c;
	line_size = 0;

	char current_line[MAXLINESIZE];

	while ((line_size = get_line(current_line, MAXLINESIZE)) != 0) {
		if (current_line[line_size] != '\n') {
			while ((c = getchar()) != '\n' && c != EOF) {
				++line_size;
			}

			if (line_size > MAXLINESIZE) {
				printf("error: line is bigger than MAXLINESIZE (%d)\n", MAXLINESIZE);
			}

		}

		reverse(current_line);
		printf("reversed line:\n%s", current_line);

		printf("\n");
	}

}
