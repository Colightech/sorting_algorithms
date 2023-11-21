#include "sort.h"

/**
 * swap_node - a function that swap 2 node in listint_t doubly-linked list.
 * @h: head node pointer
 * @nd1: node one
 * @nd2: node two
 * Return: void
 */
void swap_node(listint_t **h, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;

	if (nd2->next != NULL)
	{
		nd2->next->prev = *nd1;
	}
	nd2->prev = (*nd1)->prev;
	nd2->next = *nd1;
	if ((*nd1)->prev != NULL)
	{
		(*nd1)->prev->next = nd2;
	}
	else
		*h = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - this function that sorts a doubly linked
 * list of integers in ascending order using the Insertion sort
 * @list: the list of integer to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *copy, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		copy = curr->prev;

		while (copy != NULL && copy->n > curr->n)
		{
			swap_node(list, &copy, curr);
			print_list((const listint_t *)*list);
		}
	}
}
