/* Note: In the functions, the 'extern' keyword can be omitted because the external variables are defined in the same source file */
/* "Common practice is to place definitions of all external variables at the beginning of the source file, and then ommit all extern declarations" */
#include <stdio.h>

#define MAXSIZE 1000

int get_line(void);
void copy(void);

char current_line[MAXSIZE], max_line[MAXSIZE];
int max_line_size;

/* getline: read a line into line, return its length in i */
int get_line(void) {
	extern char current_line[];
	int c, i;
	i = 0;

	while ((c = getchar()) != '\n' && c != EOF) {
		current_line[i] = c;
		++i;
	}

	if (c == '\n') {
		current_line[i] = c;
		++i;
	}

	current_line[i] = '\0';
	return i - 1;
}	

/* copy: copy a line from 'origin' to 'duplicate' */
void copy(void) {
	int i = 0;
	extern char max_line[], current_line[];
	while ((max_line[i] = current_line[i]) != '\0') {
		++i;
	}
}
		
int main() {
	extern int max_line_size;
	extern char current_line[], max_line[];

	int line_size, i;
	line_size = i = 0;

	while ((line_size = get_line()) != 0) {
		printf("%d\n", line_size);

		if (line_size > max_line_size) {
			max_line_size = line_size;
			copy();
		}
	}


	printf("%d\n", max_line_size);
	printf("%s", max_line);
}
