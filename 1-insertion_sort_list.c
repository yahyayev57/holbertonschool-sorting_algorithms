#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes a and b in a doubly linked list
 * @list: pointer to the head of the list
 * @a: pointer to the first node
 * @b: pointer to the second node (a->next)
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	b->prev = a->prev;

	a->next = b->next;
	if (b->next)
		b->next->prev = a;

	b->next = a;
	a->prev = b;

	if (b->prev == NULL)
		*list = b;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Insertion sort algorithm
 * @list: pointer to the pointer of the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
		current = current->next;
	}
}
