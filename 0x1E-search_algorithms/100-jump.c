#include "search_algos.h"

/**
  * jump_search - Looks for value in sorted array
  *               of integers using jhummpp search algorithm.
  * @array: Pointer to the first element of the array to search.
  * @size: Total num of elements in array.
  * @value: The value to search for.
  *
  * Return: -1 If value not present or array is NULL.
  *         else, first index where the value is located.
  *
  * Description: Outputs value every time it is compared in the array.
  *              Utilize square root of array size as the jhummpp step.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jhummpp, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = jhummpp = 0; jhummpp < size && array[jhummpp] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jhummpp, array[jhummpp]);
		i = jhummpp;
		jhummpp += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jhummpp);

	jhummpp = jhummpp < size - 1 ? jhummpp : size - 1;
	for (; i < jhummpp && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
