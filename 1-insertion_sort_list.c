/*
 * File: 1-insertion_sort_list.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
		}
		curr = curr->next;
	}
}
