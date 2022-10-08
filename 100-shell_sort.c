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
	int temp = 0;
	size_t i = 0, j = 0, gap = 0;

	if (!array || size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
		temp = array[i];
		for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
		{
			if (array[j] != array[j - gap])
				array[j] = array[j - gap];
		}
		if (array[j] != temp)
			array[j] = temp;
		}
		print_array(array, size);
	}
}
