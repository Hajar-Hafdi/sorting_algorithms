#include "sort.h"
/**
*swap - swaps two nodes in a doubly-linked list
*@a: address of first node
*@b: address of second node
*
*Return: void
*/
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
*tail_traverse- function that sorts from the tail back
*
*@head: head of list
*@tail: tail of the list
*@list: original head of the list
*
*Return: new head of the list
*/
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}

/**
*cocktail_sort_list - sorts linked list using cocktail shaker sort
*
*@list: doubly linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *hed, *len;
	int u = 0, j = 0, swaped = 1;

	if (!list || !*list)
		return;
	len = *list;
	for (u = 0; len; u++)
	{
		len = len->next;
	}
	if (u < 2)
		return;
	hed = *list;
	while (j < u)
	{
		swaped = 0;
		while (hed && hed->next)
		{
			if (hed->n > hed->next->n)
			{
				swap(hed, hed->next);
				swaped++;
				if (hed->prev->prev == NULL)
					*list = hed->prev;
				print_list(*list);
			}
			else
				hed = hed->next;
			if (hed->next == NULL)
				tail = hed;
		}
		hed = tail_traverse(hed, tail, *list);
		*list = hed;
		j++;
	}
}
