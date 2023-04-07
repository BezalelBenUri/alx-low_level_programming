#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	int len = 0;

	if (b == NULL)
		return (0);

	while (b[len])
		len++;

	while (len > 0)
	{
		len--;
		if (b[len] != '0' && b[len] != '1')
			return (0);
		n = n << 1;

		if (b[len] == '1')
			n = n | 1;
	}

	return (n);
}
