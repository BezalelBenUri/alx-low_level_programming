#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to transform
 *             one number to another.
 * @n: The base number.
 * @m: The number to transform to.
 *
 * Return: The number of bit transformations needed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, res;

	res = 0;

	for (i = (8 * sizeof(n)) - 1; i >= 0; i--)
	{
		if (((n ^ m) >> i) & 1)
			res++;
	}

	return (res);
}
