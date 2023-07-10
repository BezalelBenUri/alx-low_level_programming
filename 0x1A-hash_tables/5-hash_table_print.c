#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_brch_t *brch;
	unsigned long int i;
	unsigned char indicator = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (indicator == 1)
				printf(", ");

			brch = ht->array[i];
			while (brch != NULL)
			{
				printf("'%s': '%s'", brch->key, brch->value);
				brch = brch->next;
				if (brch != NULL)
					printf(", ");
			}
			indicator = 1;
		}
	}
	printf("}\n");
}
