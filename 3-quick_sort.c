/*
 * File: 3-quick_sort.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

#include "sort.h"

/**
 * quicksort_helper - Quick sort helper function
 * @low: low
 * @high: high
 *
 */

void quicksort_helper(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = 0;
	int temp = 0;

	if (low < high)
	{
		for (j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;

		quicksort_helper(array, size, low, i + 1 - 1);
		quicksort_helper(array, size, i + 1 + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              Quick sort algorithm
 * @array: Array of integers
 * @size: Size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quicksort_helper(array, size, 0, size - 1);
}
