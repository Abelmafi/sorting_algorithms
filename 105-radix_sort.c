#include "sort.h"
#include <tsdlib.h>

/**
 *
 *
 *
 *
 */
void count_sort(int *array , size_t size)
{
	int *count, *output;

	count = malloc(sizeof(int) * size + 2);
	output = malloc(sizeof(int) * size);

	for (i = 0; i < n; i++)
		++count[(array[i] / exp) % 10];
	for (i = 0; array[i]; i++)
		count[i] += count[i - 1];

	for (i = 0; array[i]; i++)
	{
		output[count[((array[i] / exp) % 10) - 1] = array[i];
		--count[(array[i] / exp) % 10];
	}

/**
 *
 *
 *
 *
 *
 */
void radix_sort(int *array, size_t size)
{

}

