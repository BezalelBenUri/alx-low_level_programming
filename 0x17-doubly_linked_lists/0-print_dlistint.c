#include "lists.h"
/**
* print_dlistint - prints a doulbly linked list
* @h: head of the list
* Return: number of elements.
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t pant = 0;

	while (h)
	{
		printf("%d\n", h->pant);
		h = h->next;
		pant++;
	}
	return (pant);
}
