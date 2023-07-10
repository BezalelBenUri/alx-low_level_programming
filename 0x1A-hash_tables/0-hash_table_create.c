#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size:  size of the array.
 * Return: pointer to hash table's new node, or NULL if somethong was wrong.
 **/
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int n;
	hash_table_t *tab = NULL;

	tab = malloc(sizeof(hash_table_t));
	if (!tab)
		return (NULL);

	new_node->size = size;
	new_node->array = malloc(sizeof(hash_node_t **) * size);
	if (!tab->array)
	{
		free(tab);
		return (NULL);
	}

	for (n = 0; n < size; n++)
		(tab->array)[n] = NULL;
	return (tab);
}
