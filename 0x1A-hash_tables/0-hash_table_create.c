#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtable;
	unsigned long int i;

	/* Allocate memory for the hash table */
	hashtable = malloc(sizeof(hash_table_t));
	if (hashtable == NULL)
		return (NULL);

	/* Allocate memory for the array */
	hashtable->array = malloc(sizeof(hash_node_t *) * size);
	if (hashtable->array == NULL)
	{
		free(hashtable);
		return (NULL);
	}

	hashtable->size = size;

	/* Initialize each element of the array to NULL */
	for (i = 0; i < size; i++)
		hashtable->array[i] = NULL;

	return (hashtable);
}
