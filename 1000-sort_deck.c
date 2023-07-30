/*
 * File: 1000-sort_deck.c
 * Author: Oluwatobiloba Light
 */

#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void headion_sort_deck_kind(deck_node_t **deck);
void headion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * headion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void headion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *curr, *head, *temp;

	for (curr = (*deck)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		head = curr->prev;
		while (head != NULL && head->card->kind > curr->card->kind)
		{
			head->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = head;
			curr->prev = head->prev;
			curr->next = head;
			if (head->prev != NULL)
				head->prev->next = curr;
			else
				*deck = curr;
			head->prev = curr;
			head = curr->prev;
		}
	}
}

/**
 * headion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void headion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *curr, *head, *temp;

	for (curr = (*deck)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		head = curr->prev;
		while (head != NULL &&
			   head->card->kind == curr->card->kind &&
			   get_value(head) > get_value(curr))
		{
			head->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = head;
			curr->prev = head->prev;
			curr->next = head;
			if (head->prev != NULL)
				head->prev->next = curr;
			else
				*deck = curr;
			head->prev = curr;
			head = curr->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	headion_sort_deck_kind(deck);
	headion_sort_deck_value(deck);
}
