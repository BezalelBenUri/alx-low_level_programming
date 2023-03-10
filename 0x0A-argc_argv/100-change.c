#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int values[] = {25, 10, 5, 2, 1}; // array of coin values
	
	// check if there is exactly one argument
	if (argc != 2) {
		printf("Error\n");
		return 1;
	}
	
	// convert argument to integer using atoi
	cents = atoi(argv[1]);
	
	// if cents is negative, print 0 and return
	if (cents < 0) {
		printf("0\n");
		return 0;
	}
	// loop through coin values, adding the number of times each coin fits
	// into the remaining cents to the total number of coins
	for (int i = 0; i < 5; i++) {
		coins += cents / values[i];
		cents = cents % values[i];
	}
	// print the total number of coins
	printf("%d\n", coins);
	return 0;
}
