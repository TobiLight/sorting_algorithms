/*
 * File: 100-shell_sort.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @array: An array of integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_integers(array, j, (j - gap));
				j -= gap;
			}
			i++;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
