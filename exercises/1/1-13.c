#include <stdio.h>
#define MAXWORDLEN 10

int main() {
	int i, j, ch, word_count, word_length, most_word_occurrences;
	word_count = word_length = most_word_occurrences = 0;
	int word_sizes[MAXWORDLEN + 1] = {};

	while ((ch = getchar()) != EOF) {
		if (ch == '\t' || ch == '\n' || ch == ' ') {
			if (word_length > 0) {
				if (word_length <= MAXWORDLEN) {
					++word_sizes[word_length - 1];
					++word_count;
					word_length = 0;
				}

				else {
					++word_sizes[MAXWORDLEN];
					word_length = 0;
				}
			}
		}

		else {
			word_length += 1;
		}
	}

	for (i = 0; i <= MAXWORDLEN; i++) {
		if (most_word_occurrences == 0) {
			most_word_occurrences = word_sizes[i];
		}

		else {
			if (word_sizes[i] > most_word_occurrences) {
				most_word_occurrences = word_sizes[i];
			}
		}
	}


	for (i = most_word_occurrences; i > 0; i--) {
		printf("%4d │\t", i);
		for (j = 0; j <= MAXWORDLEN; j++) { 
			if (word_sizes[j] >= i) {
				printf("*   ");
			}

			else {
				printf("    ");
			}
		}
		printf("\n");
	}

	printf("     └");
	for (i = 0; i <= MAXWORDLEN; i++) {
		printf("────");
	}

	printf("\n");
	printf("      ");

	for (i = 1; i <= MAXWORDLEN + 1; i++) {
		if (i != MAXWORDLEN + 1) {
			printf("%3d ", i);
		}

		else {
			printf("%3d+\n", i);
		}

	}

}
