#include "sort.h"
#include <stdlib.h>
/**
 * get_max - searchs for max number in array.
 * @array: array to be searched.
 * @size: array size.
 *
 * Return: max number.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
 * count_sort - sorts an array of integers in ascending
 * order using the count sort algorithm as a subset of radix sort.
 * @array: array to be sorted.
 * @size: array size.
 * @exp: exponential level.
 *
 * Return: None
 */
void count_sort(int *array, int exp, size_t size)
{
	int *count, *output;
	int j;
	size_t i;

	count = malloc(sizeof(int) * size + 2);
	output = malloc(sizeof(int) * size);

	for (i = 0; i < size + 2; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		++count[(array[i] / exp) % 10];
	for (i = 0; i < size + 2; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[((array[j] / exp) % 10)] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
	print_array(array, size);
}
/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 * @array: array to be sorted.
 * @size: array size.
 *
 * Return: None.
 */
void radix_sort(int *array, size_t size)
{
	int i, max;

	max = get_max(array, size);
	for (i = 1; max / i > 0; i *= 10)
		count_sort(array, i, size);
}
