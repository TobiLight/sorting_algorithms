/*
 * File: 2-selection_sort.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
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
	size_t smallest, i = 0, j;
	int temp;

	while (i < size - 1)
	{
		smallest = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[smallest])
				smallest = j;
			j++;
		}
		if (smallest != i)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
		i++;
	}
}
