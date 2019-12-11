#include <stdio.h>

int main() {
	float celsius;
	int fahr;
	
		printf("FAHRENHEIT TO CELSIUS TABLE\n");
		printf("┌────────────┬─────────┐\n");
		printf("│ FAHRENHEIT │ CELSIUS │\n");
		printf("├────────────┼─────────┤\n");

	for (fahr = 300; fahr >= 0; fahr = fahr - 20) { 
		celsius = 5.0/9.0 * (fahr - 32.0);

		printf("│    %3d     │  %5.1f  │\n", fahr, celsius);
		printf("├────────────┼─────────┤\n");
		printf("│            │         │\n");
	}

}
