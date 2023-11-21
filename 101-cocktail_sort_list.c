#include "sort.h"

/**
 * swap_forward - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list.
 * @low: A pointer to the tail.
 * @curr: A pointer to current node.
 */
void swap_forward(listint_t **list, listint_t **low, listint_t **curr)
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
		*low = *curr;
	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * swap_backward - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @low: A pointer to the tail.
 * @curr: A pointer to the current node.
 */
void swap_backward(listint_t **list, listint_t **low, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*low = temp;
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
 * ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *low, *curr;
	bool sorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (low = *list; low->next != NULL;)
		low = low->next;

	while (sorted == false)
	{
		sorted = true;
		for (curr = *list; curr != low; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_forward(list, &low, &curr);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
		for (curr = curr->prev; curr != *list; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_backward(list, &low, &curr);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
	}
}
