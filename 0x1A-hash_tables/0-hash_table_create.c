#include "hash_tables.h"

/**
 * hash_table_create - create a hash table
 * @size: size of the table
 * Return: pointer to the table
 **/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *tabs;

	if (size == 0)
		return (NULL);
	tabs = malloc(sizeof(hash_table_t));
	if (tabs == NULL)
		return (NULL);

	tabs->size = size;
	tabs->array = calloc(size, sizeof(hash_node_t *));
	if (tabs->array == NULL)
	{
		free(tabs);
		return (NULL);
	}
	return (tabs);
}
