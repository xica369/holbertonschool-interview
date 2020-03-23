#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: list to check
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *aux1, *aux2;

	aux1 = list;
	aux2 = list->next->next;

	if (list == NULL)
		return (0);

	if (list->next == NULL)
		return (0);

	for (; aux2 != NULL; aux2 = aux2->next->next, aux1 = aux1->next)
	{
		if (aux2->next == aux1)
			return (1);
	}
	return (0);
}
