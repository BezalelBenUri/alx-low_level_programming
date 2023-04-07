#include "main.h"

/**
 * set_bit - Sets a bit at a given index to 1.
 * @n: A pointer to the number to modify.
 * @index: The index to set the bit at - indices start at 0.
 *
 * Return: 1 on success, -1 on failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n |= (1ul << index);
	return (1);
}
