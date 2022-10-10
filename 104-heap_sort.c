#include "sort.h"
/**
 * swap - swap position of two element.
 * @a: frist pointer.
 * @b: second pointer.
 * Return: none.
 */
void swap(int *a, int *b)
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
void heapify(int *array, size_t size, size_t N, int i)
{
	int largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < N && array[left] > array[largest])
		largest = left;
	if (right < N && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, N, largest);
		print_array(array, size);
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

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, size, i, 0);
		print_array(array, size);
	}
}
