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
	size_t in, lf, d;

	if (array == NULL)
		return (-1);

	for (lf = 0, d = size - 1; d >= lf;)
	{
		printf("Searching input array: ");
		for (in = lf; in < d; in++)
			printf("%d, ", array[in]);
		printf("%d\n", array[in]);

		i = lf + (d - lf) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			d = i - 1;
		else
			lf = i + 1;
	}

	return (-1);
}
