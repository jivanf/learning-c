#include <stdio.h>

#define BASE 	 -3
#define EXPONENT 3

/* Raise number x to a power y */
int power(int x, int y);

int power(x, y) {
	if (y == 0) {
		return 1;
	}

	else {
		return x * power(x, y - 1);
	}
}

int main() {
	printf("%d\n", power(BASE, EXPONENT));
	return 0;
}
