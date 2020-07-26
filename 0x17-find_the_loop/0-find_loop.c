#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 *
 * @head: pointer to head of the list
 *
 * Return: node's address where the loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head)
		return (NULL);

	slow = head;
	fast = head;

	for (; !slow && !fast && !fast->next;
	     slow = slow->next, fast = fast->next->next)
	{
		if (slow == fast && slow == head)
			return (head);

		if (slow == fast && fast != head)
		{
			head = head->next;
			slow = head;
			fast = head;
		}
	}
	return (NULL);
}
