#include <stdio.h>

#define OUT_STRING      0
#define IN_STRING       1

#define OUT_COMMENT     0
#define IN_COMMENT      1 

int main() {
	// slash_comment: check for start and end of double slash comments
	/* asterisk_comment: check for start and end of slash and asterisk comments */
	// single_quotation: check if we are in a character constant ('')
	/* double_quotation: check if we are in a string ("") */
	int ch, double_quotation, single_quotation, slash_comment, asterisk_comment;
	double_quotation = single_quotation = slash_comment = asterisk_comment = 0;

	while ((ch = getchar()) != EOF) {	
		if (ch == '\"') {
			if (double_quotation == OUT_STRING) {
				double_quotation = IN_STRING;
			}

			else {
				double_quotation = OUT_STRING;
			}
		}

		if (ch == '\'') {
			if (single_quotation == OUT_STRING) {
				single_quotation = IN_STRING;
			}

			else {
				single_quotation = OUT_STRING;
			}
		}

		int next_ch = 0;

		if (!double_quotation && !single_quotation) {
			if (ch == '/') {
				next_ch = getchar();
				if (next_ch == '/') {
					slash_comment = IN_COMMENT;
				}

				if (next_ch == '*') {
					asterisk_comment = IN_COMMENT;
				}

			}


			if (ch == '\n') {
				slash_comment = OUT_COMMENT;
			}
		}

		if (slash_comment != IN_COMMENT && asterisk_comment != IN_COMMENT) {
			printf("%c", ch);

			if (next_ch) {
				printf("%c", next_ch);
			}

		}

		if (!double_quotation && !single_quotation) {
			if (ch == '*') {
				next_ch = getchar();
				if (next_ch == '/') {
					asterisk_comment = OUT_COMMENT;
				}
			}
		}


	}
}
