#include "hash_tables.h"

/**
 * key_index - Returns the index of a key in the hash table array
 * @key: The key
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	/* Calculate the hash value using hash_djb2 */
	hash_value = hash_djb2(key);

	/* Calculate the index within the size of the hash table */
	index = hash_value % size;

	return (index);
}
