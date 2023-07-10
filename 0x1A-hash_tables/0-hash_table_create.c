#include "hash_tables.h"

/**
 * hash_table_create - create a hash table
 * @size: size of the table
 * Return: pointer to the table
 **/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashs_table;

	if (size == 0)
	return (NULL);
	hashs_table = malloc(sizeof(hash_table_t));
	if (hashs_table == NULL)
		return (NULL);

	hashs_table->size = size;
	hashs_table->array = calloc(size, sizeof(hash_node_t *));
	if (hashs_table->array == NULL)
	{
		free(hashs_table);
		return (NULL);
	}
	return (hashs_table);
}
