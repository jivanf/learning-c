#include <stdio.h>

#define BEGIN 300
#define END 0
#define STEP 20

int main() {
	float celsius;
	int fahr;
	
		printf("FAHRENHEIT TO CELSIUS TABLE\n");
		printf("┌────────────┬─────────┐\n");
		printf("│ FAHRENHEIT │ CELSIUS │\n");
		printf("├────────────┼─────────┤\n");

	for (fahr = BEGIN; fahr >= END; fahr = fahr - STEP) { 
		celsius = 5.0/9.0 * (fahr - 32.0);

		printf("│    %3d     │  %5.1f  │\n", fahr, celsius);
		printf("├────────────┼─────────┤\n");
		printf("│            │         │\n");
	}

}
