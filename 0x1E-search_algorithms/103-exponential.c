#include "search_algos.h"

/**
  * _binary_search - Looks for a value using binary search algorithm.
  * @array: Pointer to first element of array to search.
  * @left: Starting index
  * @right: Ending index
  * @value: Value to search for.
  *
  * Return: NULL, -1,index where value is located.
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mn;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (mn = left; mn < right; mn++)
			printf("%d, ", array[mn]);
		printf("%d\n", array[mn]);

		mn = left + (right - left) / 2;
		if (array[mn] == value)
			return (mn);
		if (array[mn] > value)
			right = mn - 1;
		else
			left = mn + 1;
	}

	return (-1);
}

/**
* exponential_search - Searches using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The size of the array.
  * @value: The value to search for.
  *
  * Return: NULL, -1, the index where the value is located.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t mn = 0, rite;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (mn = 1; mn < size && array[mn] <= value; mn = mn * 2)
			printf("Value checked array[%ld] = [%d]\n", mn, array[mn]);
	}

	if (mn < size)
		rite = mn;
	else
		rite = size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", mn / 2, rite);
	return (_binary_search(array, mn / 2, rite, value));
}
