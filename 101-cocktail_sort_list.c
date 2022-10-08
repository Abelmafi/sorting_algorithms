#include "sort.h"
/**
 * swap - swap two linked list nodes.
 * @left: left side of swap node.
 * @right: right side of swap nodes.
 *
 * Return: always none.
 */
void swap(listint_t **left, listint_t **right)
{
	listint_t *temp = (*left)->prev;

	(*left)->next = (*right)->next;
	(*left)->prev = *right;
	(*right)->next = *left;
	(*right)->prev = temp;
	if ((*right)->prev)
		(*right)->prev->next = *right;
	if ((*left)->next)
		(*left)->next->prev = *left;
}

/**
 * cocktail_sort_list - sort a list using cocktail_sort method.
 * @list: linked list to be sorted.
 *
 * Return: None.
 */
void cocktail_sort_list(listint_t **list)
{
	int c = 0, n = -1, m = -1;
	listint_t *current = *list, *temp;

	while (m >= n)
	{
		n++;
		while (current->next && c != m)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				swap(&current, &temp);
				current = temp;
				if ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
			current = current->next;
			c++;
		}
		if (n == 0)
			m = c;
		m--;
		while (current->prev && c >= n)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				swap(&temp, &current);
				current = temp;
				if ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
			c--;
			current = current->prev;
		}
	}
}
