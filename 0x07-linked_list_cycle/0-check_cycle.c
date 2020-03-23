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

	if (list == NULL)
		return (0);

	if (list->next == NULL)
		return (0);

	aux1 = list;
	aux2 = list->next->next;

	for (; aux2 != NULL; aux1 = aux1->next)
	{
		if (aux2 == aux1)
			return (1);

		aux2 = aux2->next->next;
	}
	return (0);
}
