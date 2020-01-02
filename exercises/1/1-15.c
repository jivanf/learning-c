#include <stdio.h>

#define BEGIN 10
#define END   200
#define STEP  10

float fahr_to_celsius(float fahr);

float fahr_to_celsius(float fahr) {
	return (fahr - 32) * 5/9;
}

int main() {
	int fahr;
	float celsius;

	fahr = BEGIN;
	printf("FAHRENHEIT TO CELSIUS TABLE\n");
	printf("┌────────────┬─────────┐\n");
	printf("│ FAHRENHEIT │ CELSIUS │\n");
	printf("├────────────┼─────────┤\n");
	while (fahr <= END) {
		celsius = fahr_to_celsius(fahr);
		printf("│    %3d     │  %5.1f  │\n", fahr, celsius);

		if (fahr + STEP > END) {
			printf("└────────────┴─────────┘\n");
		}
		else {
			printf("├────────────┼─────────┤\n");
			printf("│            │         │\n");
		}
		fahr += STEP;
	}
}
	
