#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - sorts doubly linked list of intigiers
 * in ascending order.
 * @list: doubly linked list
 *
 * Return: always nothng.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *right=NULL, *left=NULL;
	listint_t *current = *list, *temp=NULL;

	while(current->next)
	{
		temp = current;
		current = current->next;
		while (temp)
		{
			right = temp->next;
			left = temp;
			temp = temp->prev;
			if (left->n > right->n)
			{
				if (temp)
					temp->next = right;

				right->prev = temp;
				left->prev = right;
				left->next = right->next;
				right->next = left;
				if (left->next)
					left->next->prev = left;
				while((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
		}
	}
}
