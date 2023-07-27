/*
 * File: 1-insertion_sort_list.c
 * Authors: Oluwatobiloba Light & Favour Uzochukwu
 */

#include "sort.h"

/**
 * insertion_sort_list - Swap two nodes in a listint_t doubly-linked list.
 * @list: list of node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *head, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next = curr->next;
		head = curr->prev;
		while (head != NULL && curr->n < head->n)
		{
			head->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = head;

			curr->prev = head->prev;
			curr->next = head;
			if (head->prev != NULL)
				head->prev->next = curr;
			else
				*list = curr;

			head->prev = curr;
			head = curr->prev;
			print_list((const listint_t *)*list);
		}
		curr = next;
	}
}
