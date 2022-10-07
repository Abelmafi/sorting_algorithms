#include "sort.h"

/**
 * swap - swap contents of given array.
 * @array: array input
 * @i: array first index;
 * @j: array second index.
 *
 * Return: always nothing.
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - This function takes last element as pivot,
 * places the pivot element at its correct position
 * in sorted array, and places all smaller
 * (smaller than pivot) to left of pivot and all
 * greater elements to right of pivot.
 *
 * @array: array to be sorted.
 * @low: Starting index.
 * @high: Ending index.
 * @size: array size.
 *
 * Return: partion index.
 */
int partition(int *array, int low, int high, int size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != high)
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - implements QuickSort.
 * @array: array to be sorted.
 * @low: Starting index.
 * @high: ending index.
 * @size: array size.
 *
 * Return: always nothing
 */
void quicksort(int *array, int low, int high, int size)
{
	int p;

	if (low >= high || low < 0)
		return;
	if (low < high)
	{
	p = partition(array, low, high, size);

	quicksort(array,  low, p - 1, size);
	quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - The main function that implements QuickSort.
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: always nothing
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	quicksort(array, low, high, size);
}
