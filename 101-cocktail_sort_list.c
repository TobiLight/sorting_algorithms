/*
 * File: 101-cocktail_sort_list.c
 * Authors: Oluwatobiloba Light
 */

#include "sort.h"

void swap_front_node(listint_t **, listint_t **, listint_t **);
void swap_back_node(listint_t **, listint_t **, listint_t **);
void cocktail_sort_list(listint_t **);

/**
 * swap_front_node - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_front_node(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*curr)->prev;
	(*curr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swap_back_node - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_back_node(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*curr)->next;
	(*curr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = temp;
	temp->prev = *curr;
	*curr = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *curr;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next != NULL)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;

		curr = *list;
		while (curr != tail)
		{
			if (curr->n > curr->next->n)
			{
				swap_front_node(list, &tail, &curr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
			curr = curr->next;
		}

		curr = curr->prev;
		while (curr != *list)
		{
			if (curr->n < curr->prev->n)
			{
				swap_back_node(list, &tail, &curr);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
			curr = curr->prev;
		}
	}
}
