#include "sort.h"
#include <stdio.h>
/**
 * swap - swap two array elements.
 * @array: array to be swaped.
 * @i: first element index.
 * @j: second element index.
 *
 * Return: None.
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
/**
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sozred.
 * @low: array lower index.
 * @high: array higher index.
 * @size: array size.
 *
 * Return: None.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swap(array, low, high);
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}
/**
 * quick_sortt - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sozred.
 * @low: array lower index.
 * @high: array higher index.
 * @size: array size.
 *
 * Return: None.
 */
void quick_sortt(int *array, size_t low, size_t high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);

		quick_sortt(array, low, p, size);
		quick_sortt(array, p + 1, high, size);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sozred.
 * @size: array size.
 *
 * Return: None.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sortt(array, 0, size - 1, size);
}
