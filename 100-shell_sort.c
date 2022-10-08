#include "sort.h"
/**
 * shell_sort - sorts the elements of array by exchange of far items
 * in sorting order.
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: None.
 */
void shell_sort(int *array, size_t size)
{
	int interval = 0, temp;
	size_t i, j, g = 0, gap;

	while (g < size / 3)
	{
		g = (interval * 3) + 1;
		interval++;
	}
	for (gap = g; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
		for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			array[j] = array[j - gap];
		array[j] = temp;
		}
		print_array(array, size);
	}
}
