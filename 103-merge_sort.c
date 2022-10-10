#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * merge_half - merge sorted array in sorted manner.
 * @array: array to be merged.
 * @l_start: array starting index.
 * @mid: array mid index.
 * @r_end: array ending index.
 *
 * return: None.
 */
void merge_half(int *array, int l_start, int mid, int r_end)
{
	int l_size = mid - l_start + 1;
	int r_start = mid + 1;
	int r_size = r_end - mid;
	int L[l_size], R[r_size];
	int i, j, index = l_start;

	for (i = 0; i < l_size; i++)
		L[i] = array[l_start + i];
	for (j = 0; j < r_size; j++)
		R[j] = array[r_start + j];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, i);
	printf("[right]: ");
	print_array(R, j);
	i = 0;
	j = 0;
	while (i < l_size && j < r_size)
	{
		if (L[i] <= R[j])
		{	array[index] = L[i];
			i++;	}
		else
		{	array[index] = R[j];
			j++;	}
		index++;
	}
	while (i < l_size)
	{	array[index] = L[i];
		i++;
		index++;	}
	while (j < r_size)
	{	array[index] = R[j];
		j++;
		index++;	}
	printf("[Done]: ");
	print_array(array, index);
}
/**
 * merge_sortt - sort a given array using merge soart algorithm.
 * @array: array to be sorted.
 * @left_start: array starting index.
 * @right_end: array last index.
 * @size: array size.
 *
 * Return: None.
 */
void merge_sortt(int *array, int left_start, int right_end, int size)
{
	int middle;

	if (left_start < right_end)
	{
		middle = (left_start + right_end) / 2;

		merge_sortt(array, left_start, middle, size);
		merge_sortt(array, middle + 1, right_end, size);

		merge_half(array, left_start, middle, right_end);
	}
}
/**
 * merge_sort -  sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array to e sorted.
 * @size: array size.
 *
 * Return: None.
 */
void merge_sort(int *array, size_t size)
{
	merge_sortt(array, 0, size - 1, size);
	print_array(array, size);
}
