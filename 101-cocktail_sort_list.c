#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integer
 * using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the pointer of the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				if (current->next != NULL)
					current->next->prev = current;
				current->prev->next = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				if (current->next != NULL)
					current->next->prev = current->prev;
				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;
				if (current->prev != NULL)
					current->prev->next = current;
				else
					*list = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	} while (swapped);
}
