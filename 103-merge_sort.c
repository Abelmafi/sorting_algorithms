#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * merge_half - merge sorted array in sorted manner.
 * @array: array to be merged.
 * @buff: temporary buffer array.
 * @l_start: array starting index.
 * @mid: array mid index.
 * @r_end: array ending index.
 *
 * return: None.
 */
void merge_half(int *array, int *buff, int l_start, int mid, int r_end)
{
	int r_start = mid;
	int l_end = mid;
	int r = r_start, l = l_start;
	int i = 0, j;

	printf("Merging...\n[left]: ");
	print_array(array + l_start, mid - l_start);
	printf("[right]: ");
	print_array(array + r_start, r_end - mid);

	while (l < l_end && r < r_end)
		buff[i++] = (array[l] <= array[r]) ? array[l++] : array[r++];
	while (l < l_end)
		buff[i++] = array[l++];
	while (r < r_end)
		buff[i++] = array[r++];
	for (j = l_start, i = 0; j < r_end; j++)
		array[j] = buff[i++];
	printf("[Done]: ");
	print_array(array + l_start, r_end - l_start);
}
/**
 * merge_sortt - sort a given array using merge soart algorithm.
 * @array: array to be sorted.
 * @buff: temporary buffer array.
 * @left_start: array starting index.
 * @right_end: array last index.
 *
 * Return: None.
 */
void merge_sortt(int *array, int *buff,  int left_start, int right_end)
{
	int middle;

	if (right_end - left_start > 1)
	{
		middle = left_start + (right_end - left_start) / 2;

		merge_sortt(array, buff, left_start, middle);
		merge_sortt(array, buff, middle, right_end);

		merge_half(array, buff, left_start, middle, right_end);
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
	int *buff;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	merge_sortt(array, buff,  0, size);
	free(buff);
}
