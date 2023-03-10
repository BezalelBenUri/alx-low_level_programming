#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: the number of arguments
 * @argv: an array containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
/* to suppress unused variable warning */
	argv = argv;
	printf("%d\n", argc - 1);
	return (0);
}
