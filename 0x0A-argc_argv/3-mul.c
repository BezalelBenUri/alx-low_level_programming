#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: the number of arguments passed to the program
 * @argv: an array containing the arguments passed to the program
 *
 * Return: 0 if multiplication was successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	/* Convert arguments into int */
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	int result = num1 * num2;

	printf("%d\n", result);

	return (0);
}
