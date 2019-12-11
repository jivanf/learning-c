#include <stdio.h>

int main() {
	float celsius;
	int fahr, begin, end, step;

	begin = 0;
	end = 300;
	step = 20;
	
	fahr = begin;
	printf("FAHRENHEIT TO CELSIUS TABLE\n");
	printf("┌────────────┬─────────┐\n");
	printf("│ FAHRENHEIT │ CELSIUS │\n");
	printf("├────────────┼─────────┤\n");
	while (fahr <= end) {
		celsius = 5.0/9.0 * (fahr - 32.0);

		printf("│ %3d        │%6.1f   │\n", fahr, celsius);
		printf("├────────────┼─────────┤\n");
		printf("│            │         │\n");

		fahr = fahr + step;
	}

}
