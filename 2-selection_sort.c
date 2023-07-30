/*
 * File: 2-selection_sort.c
 * Authors: Oluwatobiloba Light
 */

#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending order with
 *                  selection sort
 * @array: array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int *smallest, temp;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		smallest = array + i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[*smallest])
				smallest = array + j;
			j++;
		}
		if ((array + i) != smallest)
		{
			temp = array + i;
			*(array + i) = smallest;
			*smallest = temp;
			print_array(array, size);
		}
		i++;
	}
}
