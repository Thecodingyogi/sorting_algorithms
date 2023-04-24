#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: Integers to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i = *list;
	listint_t *j, *temp;

	if (list == NULL || i == NULL || i->next == NULL)
		return;
	for (i = *list; i->next != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->n > j->n)
			{
				temp = j->n;
				j->n = i->n;
				i->n = temp;
				print_list(*list);
			}
		}
	}
}
