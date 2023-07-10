#include "hash_tables.h"

/**
 * hash_djb2 - hash function generates a djb2
 * @str: pointer to chars a hash
 * Return: hash key
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hshs = 5381;
	int n;

	while ((n = *str++))
	hshs = ((hshs << 5) + hshs) + c; /* hash * 33 + c */

	return (hshs);
}
