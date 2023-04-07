#include "main.h"
/**
 * print_binary -  prints the binary representation of a number
 * @n: integer to convert
 */
void print_binary(unsigned long int n)
{
	int i = sizeof(n) * 8 - 1;
	int flag = 0;

	if (n == 0)
		_putchar('0');
	else
	{
		do {
			if ((n >> i) & 1)
				flag = 1;
			if (flag == 1)
				((n >> i) & 1) ? _putchar('1') : _putchar('0');
			i--;
		} while (i >= 0);
	}
}
