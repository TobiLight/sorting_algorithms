#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

/*
 * File: sort.h
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_front_node(listint_t **, listint_t **, listint_t **);
void swap_back_node(listint_t **, listint_t **, listint_t **);
void cocktail_sort_list(listint_t **);
int get_max_value(int *, int);
void counting_sort(int *, size_t);
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
