#include "search_algos.h"

/**
 * linear_skip - Looks for an algorithm in a sorted singly
 *               linked list of integers using linear skip.
 * @list: Pointer to the  head of the linked list to search.
 * @value: Value to search for.
 *
 * Return: Null, if value is not present or the head of the list is NULL.
 *         Else, a pointer to first node where the value is located.
 *
 * Description: Output value every time it is compared in the list.
 *              Using square root of the list size as the leap step.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *leap;

	if (list == NULL)
		return (NULL);

	for (node = leap = list; leap->next != NULL && leap->n < value;)
	{
		node = leap;
		if (leap->express != NULL)
		{
			leap = leap->express;
			printf("Value checked at index [%ld] = [%d]\n",
					leap->index, leap->n);
		}
		else
		{
			while (leap->next != NULL)
				leap = leap->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, leap->index);

	for (; node->index < leap->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
