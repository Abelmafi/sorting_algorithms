#include "sort.h"
/**
 * selction_sort - sorts an array of integers in ascending order.
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: always nothing.
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, index;

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