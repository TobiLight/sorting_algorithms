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
		head = (*list);
		next = curr->next;
		while (head != curr && curr->n > head->n)
			head = head->next;
		if (head != curr)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;

			curr->next = head;
			curr->prev = head->prev;
			head->next->prev = curr->next;
			if (head->prev == NULL)
				*list = curr;
			else
			{
				head->prev->next = curr;
				head->prev = curr;
			}
		}
		print_list((const listint_t *)*list);
		curr = next;
	}
}
