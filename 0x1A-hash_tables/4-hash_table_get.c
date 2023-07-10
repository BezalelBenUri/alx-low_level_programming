#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_branch_t *branch;
	unsigned long int adrs;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	adrs = key_adrs((const unsigned char *)key, ht->size);
	if (adrs >= ht->size)
		return (NULL);

	branch = ht->array[adrs];
	while (branch && strcmp(branch->key, key) != 0)
		branch = branch->next;

	return ((branch == NULL) ? NULL : branch->value);
}
