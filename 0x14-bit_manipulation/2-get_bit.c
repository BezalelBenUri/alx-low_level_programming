#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: input long integer
 * @index: index to start at
 *
 * Return: value of the bit at the index, or -1 if index is out of range
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (8 * sizeof(n) - 1))
		return (-1);
	return ((n >> index) & 1);
}
