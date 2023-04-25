#include "sort.h"

/**
 * swap - swap two nodes
 * @head: pointer to the head
 * @node1: pointer to the first node
 * @node2: The second node
 */

void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: A pointer to the head of a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *current, *temp;

	if (!list || !*list)
		return;
	for (node = (*list)->next; node != NULL; node = temp)
	{
		temp = node->next;
		current = node->prev;
		while (current != NULL && node->n < current->n)
		{
			swap(list, &current, node);
			print_list((const listint_t *)*list);
		}
	}
}
