#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - sorts an array of intigers in ascending order.
 * @array: array of intigers.
 * @size: size of array.
 *
 * Return: always nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int temp, i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
