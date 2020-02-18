#include <stdio.h>

#define OUT  0
#define IN   1

int main () {
	int open_par = 0, closed_par = 0, open_square = 0, closed_square = 0, open_curly = 0, closed_curly = 0, single_quot_count = 0, double_quot_count = 0;
	int in_double_quot = OUT, in_single_quot = OUT;
	int escape_toggle = 0;
	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == '\"') {
			if (in_double_quot == OUT) {
				in_double_quot = IN;
			}

			else {
				in_double_quot = OUT;
			}
		}

		if (ch == '\'') {
			if (in_single_quot == OUT) {
				in_single_quot = IN;
			}

			else {
				in_single_quot = OUT;
			}
		}

		if (ch == '\\') {		
			escape_toggle = 1;
		}	

		if (ch == '\"') {
			if (escape_toggle == 0 && escape_toggle != 2) {
				++double_quot_count;
			}
		}

		if (ch == '\'') {
			if (escape_toggle == 0 && escape_toggle != 2) {
				++single_quot_count;
			}
		}

		if (!in_double_quot && !in_single_quot) {
			switch (ch) {
				case '(':
					++open_par;
					break;
				case ')':
					++closed_par;
					break;
				case '[':
					++open_square;
					break;
				case ']':
					++closed_square;
					break;
				case '{':
					++open_curly;
					break;
				case '}':
					++closed_curly;
					break;
			}
		}

		if ((++escape_toggle) == 3) {
			escape_toggle = 0;
		}
	}

	if (open_par != closed_par) {
		printf("ERROR: UNBALANCED PARENTHESES\n");
	}

	if (open_square != closed_square) {
		printf("ERROR: UNBALANCED SQUARE BRACKETS\n");
	}

	if (open_curly != closed_curly) {
		printf("ERROR: UNBALANCED CURLY BRACES\n");
	}

	if (single_quot_count % 2 != 0) {
		printf("ERROR: UNBALANCED SINGLE QUOTES\n");
	}

	if (double_quot_count % 2 != 0) {
		printf("ERROR: UNBALANCED DOUBLE QUOTES\n");
	}

}



