#include <stdio.h>

#define MAXSIZE 5

int get_line(char line[], int max_len);
void copy(char origin[], char duplicate[]);

/* getline: read a line into line, return its length in i */
int get_line(char line[], int max_len) {
	int c, i;
	i = 0;

	while ((c = getchar()) != '\n' && c != EOF) {
		line[i] = c;
		++i;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i - 1;
}	

/* copy: copy a line from 'origin' to 'duplicate' */
void copy(char origin[], char duplicate[]) {
	int i = 0;
	while ((duplicate[i] = origin[i]) != '\0') {
		++i;
	}
}
		
int main() {
	int line_size, max_line_size, i;
	line_size = max_line_size = i = 0;
	char current_line[MAXSIZE];
	char max_line[MAXSIZE];
	while ((line_size = get_line(current_line, MAXSIZE)) != 0) {
		printf("%d\n", line_size);

		if (line_size > max_line_size) {
			max_line_size = line_size;
			copy(current_line, max_line);
		}
	}


	printf("%d\n", max_line_size);
	printf("%s", max_line);
}
