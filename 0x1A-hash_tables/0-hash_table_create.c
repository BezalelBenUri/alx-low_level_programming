#include "hash_tables.h"
/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: hash table pointer
**/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *var_table;
	hash_node_t **var_array;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	var_array = malloc(sizeof(hash_node_t *) * size);
	if (var_array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		array[i] = NULL;
	}
	var_table = malloc(sizeof(hash_table_t));
	if (var_table == NULL)
		return (NULL);
	var_table->array = var_array;
	var_table->size = size;
	return (var_table);
}
