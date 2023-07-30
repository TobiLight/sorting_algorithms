/*
 * File: 102-counting_sort.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

#include "sort.h"

/**
 * get_max_value - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max_value(int *array, int size)
{
	int max = array[0], i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max_value(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}
	i = 0;
	while (i < (max + 1))
	{
		count[i] = 0;
		i++;
	}
	i = 0;
	while (i < (int)size)
	{
		count[array[i]] += 1;
		i++;
	}
	i = 0;
	while (i < (max + 1))
	{
		count[i] += count[i - 1];
		i++;
	}
	print_array(count, max + 1);
	i = 0;
	while (i < (int)size)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
		i++;
	}
	i = 0;
	while (i < (int)size)
	{
		array[i] = sorted[i];
		i++;
	}
	free(sorted);
	free(count);
}
