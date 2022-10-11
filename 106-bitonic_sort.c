#include "sort.h"
#include <stdio.h>
/**
 * comp_swap - compare and swap array pointer according to direction.
 * @array: array input
 * @size: array size.
 * @dir: array sorting directory flag.
 *
 * Return: none.
 */
void comp_swap(int *array, size_t size, int dir)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == dir)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}

}
/**
 * bitonic_merge - recursively sorts a bitonic
 * sequence in ascending order
 * @array: array to be sorted.
 * @r_end: dicomposed array size
 * @dir: direction flag.
 *
 * Return: None.
 */
void bitonic_merge(int *array, int r_end, int dir)
{
	int mid;

	if (r_end > 1)
	{
		mid = r_end / 2;
		comp_swap(array, r_end, dir);
		bitonic_merge(array, mid, dir);
		bitonic_merge(array + mid, mid, dir);
	}
}
/**
 * bitonicSort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: array to be sorted.
 * @r_end: dicomposed array size
 * @size: array size
 * @dir: direction flag.
 *
 * Return: None.
 */
void bitonicSort(int *array, int r_end, size_t size, int dir)
{
	if (r_end > 1)
	{
		printf("Merging [%d/%lu] (%s):\n", r_end, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array, r_end);
		bitonicSort(array, r_end / 2, size, 1);
		bitonicSort(array + (r_end / 2), r_end / 2, size, 0);
		bitonic_merge(array, r_end, dir);
		printf("Result [%d/%lu] (%s):\n", r_end, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array, r_end);
	}
}
/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array to sorted.
 * @size: array size.
 *
 * Return: None.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonicSort(array, size, size, 1);
}
