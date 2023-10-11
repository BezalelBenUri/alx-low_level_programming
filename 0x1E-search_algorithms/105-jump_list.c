#include "search_algos.h"

/**
 * jump_list - Looks for an algorithm in a sorted singly
 *             linked list of integers using jump search algorithm.
 * @list: Pointer to the  head of the linked list to search.
 * @size: Number of nodes in the list.
 * @value: Value to search.
 *
 * Return: Null If the value not present or the head of lists NULL, NULL.
 *         Else, a pointer to first node where value is located.
 *
 * Description: Outputs a value every time it's compared in the list.
 *              Using square root of the list size as the jump leap.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t leap, leap_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	leap = 0;
	leap_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (leap += leap_size; jump->index < leap; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
