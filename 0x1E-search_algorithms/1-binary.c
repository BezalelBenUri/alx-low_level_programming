#include "search_algos.h"

/**
  * binary_search - Looks for value in sorted array
  *                 of integers using binary search algorithm.
  * @array: Pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: -1 If the value is not present or array is NULL.
  *         Else, the index where the value is located.
  *
  * Description: Output the [sub]array being searched after each change.
  */
int binary_search(int *array, size_t size, int value)
{
	int left = 0;           /* Left bound of the search range*/
	int right = size - 1;   /* Right bound of the search range*/
	int med;
	size_t i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		mid = left + (right - left) / 2; /* Calculate the middle index*/

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
			{
				printf(", ");
			}
		}
		printf("\n");

		if (array[mid] == value)
		{
			return (mid); /* Value found, return its index*/
		} else if (array[mid] < value)
		{
			left = mid + 1; /* Adjust the left bound*/
		}
		else
		{
			right = mid - 1; /* Adjust the right bound*/
		}
	}
	return (-1);
}
