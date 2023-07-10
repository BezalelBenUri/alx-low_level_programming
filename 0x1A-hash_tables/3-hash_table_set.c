#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *recent;
	char *val_copy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_cpy = strdup(value);
	if (val_cpy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = val_cpy;
			return (1);
		}
	}

	recent = malloc(sizeof(hash_node_t));
	if (recent == NULL)
	{
		free(val_cpy);
		return (0);
	}
	recent->key = strdup(key);
	if (recent->key == NULL)
	{
		free(recent);
		return (0);
	}
	recent->value = val_cpy;
	recent->next = ht->array[index];
	ht->array[index] = recent;

	return (1);
}
