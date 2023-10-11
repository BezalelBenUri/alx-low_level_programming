#include "search_algos.h"

/**
  * interpolation_search - Looks for value in sorted array
  *                        of integers using interpolation search algorithm.
  * @array: Pointer to first element of array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: -1 if value not present or the array is NULL.
  *         Else, first index where the value is located.
  *
  * Description: Outputs a value every time it is compared in the array..
  */
int interpolation_search(int *array, size_t size, int value)
{
	size_t in, l, r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		in = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		if (in < size)
			printf("Value checked array[%ld] = [%d]\n", in, array[in]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", in);
			break;
		}

		if (array[in] == value)
			return (in);
		if (array[in] > value)
			r = in - 1;
		else
			l = in + 1;
	}

	return (-1);
}
