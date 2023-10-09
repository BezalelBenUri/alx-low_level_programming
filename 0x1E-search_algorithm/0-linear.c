#include "search_algos.h"

/**
  * linear_search - Searches for a value in an array
  *                 of integers using linear search algorithm.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: -1, If value not present or the array is NULL.
  *         Else, the first index where the value is located.
  *
  * Description: Outputs a value when compared in the array.
  */
int linear_search(int *array, size_t size, int value)
{
	size_t ni;

	if (array == NULL)
		return (-1);

	for (ni = 0; ni < size; ni++)
	{
		printf("Value checked array[%ld] = [%d]\n", ni, array[ni]);
		if (array[ni] == value)
			return (ni);
	}

	return (-1);
}
