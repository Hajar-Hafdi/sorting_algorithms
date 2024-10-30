#include "sort.h"

/**
 * swap - swaps 2 nodes
 *
 * @first_node: add of 1st node
 * @second_node:  add of 2nd nose
 *
 * Return: void
 */
void swap(listint_t *first_node, listint_t *second_node)
{
	if (first_node->prev)
		first_node->prev->next = second_node;
	if (second_node->next)
		second_node->next->prev = first_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;
}
/**
 * insertion_sort_list - inserts sort a doubly lst
 *
 * @list: add of ptr
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *u, *k;

	if (!list || !*list || !(*list)->next)
		return;
	u = (*list)->next;
	while (u)
	{
		k = u;
		u = u->next;
		while (k && k->prev)
		{
			if (k->prev->n > k->n)
			{
				swap(k->prev, k);
				if (!k->prev)
					*list = k;
				print_list((const listint_t *)*list);
			}
			else
				k = k->prev;
		}
	}
}
