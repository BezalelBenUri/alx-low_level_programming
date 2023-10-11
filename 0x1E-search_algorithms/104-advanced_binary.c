#include "search_algos.h"

/**
  * advanced_binary_recursive - Looks recursively for value in sorted
  * array of integers using binary search algorithm.
  * @array: Pointer to the first element of the [sub]array to search.
  * @left: Starting index of the [sub]array to search.
  * @right: Ending index of the [sub]array to search.
  * @value: Value to search for.
  *
  * Return: -1 If the value is not present.
  *         Else the index where the value is located.
  *
  * Description: Outputs the [sub]array being searched after each change.
  */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mn;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (mn = left; mn < right; mn++)
		printf("%d, ", array[mn]);
	printf("%d\n", array[mn]);

	mn = left + (right - left) / 2;
	if (array[mn] == value && (mn == left || array[mn - 1] != value))
		return (mn);
	if (array[mn] >= value)
		return (advanced_binary_recursive(array, left, mn, value));
	return (advanced_binary_recursive(array, mn + 1, right, value));
}

/**
  * advanced_binary - Searches for a value in a sorted array
  *                   of integers using advanced binary search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
