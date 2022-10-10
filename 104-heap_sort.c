#include "sort.h"

void swap_int(int *a, int *b);
void heapify(int *array, size_t size, size_t N, size_t i);
void heap_sort(int *array, size_t size);
/**
 * swap_inr - swap position of two element.
 * @a: frist pointer.
 * @b: second pointer.
 * Return: none.
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - heapify a subtree rooted with node i.
 * @array: array to be sorted.
 * @size: array size.
 * @N: array size.
 * @i: current index.
 *
 * Return: none.
 */
void heapify(int *array, size_t size, size_t N, size_t i)
{
	size_t left, right, largest;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < N && array[left] > array[largest])
		largest = left;
	if (right < N && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(array + i, array + largest);
		print_array(array, size);
		heapify(array, size, N, largest);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: None.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
