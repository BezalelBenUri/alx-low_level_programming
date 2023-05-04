#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */

void print_binary(unsigned long int n)
{
	int len = sizeof(unsigned long int) * 8;
	int i;
	int flag = 0;

	for (i = len - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
			_putchar('0');
	}
	if (!flag)
		_putchar('0');
}
