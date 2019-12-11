#include <stdio.h>

#define BEGIN 0
#define END 420
#define STEP 20

int main() {
	float celsius;
	int fahr;
	
	printf("FAHRENHEIT TO CELSIUS TABLE\n");
	printf("┌────────────┬─────────┐\n");
	printf("│ FAHRENHEIT │ CELSIUS │\n");
	printf("├────────────┼─────────┤\n");

	for (fahr = BEGIN; fahr <= END; fahr = fahr + STEP) { 
		celsius = 5.0/9.0 * (fahr - 32.0);

		printf("│    %3d     │  %5.1f  │\n", fahr, celsius);

		if (fahr + STEP > END) {
			printf("└────────────┴─────────┘\n");
		}
		else {
			printf("├────────────┼─────────┤\n");
			printf("│            │         │\n");
		}
	}

}
