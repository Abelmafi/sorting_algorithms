#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: always nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, index;

	if (size <= 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}
		if (min < array[i])
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}

}
