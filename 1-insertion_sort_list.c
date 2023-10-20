#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			if (prev->next != NULL)
				prev->next->prev = prev;
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
