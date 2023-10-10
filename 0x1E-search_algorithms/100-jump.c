#include "search_algos.h"

/**
  * jump_search - Looks for value in sorted array
  *               of integers using jump search algorithm.
  * @array: Pointer to the first element of the array to search.
  * @size: Total num of elements in array.
  * @value: The value to search for.
  *
  * Return: -1 If value not present or array is NULL.
  *         else, first index where the value is located.
  *
  * Description: Outputs value every time it is compared in the array.
  *              Utilize square root of array size as the jump step.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
