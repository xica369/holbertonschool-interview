#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 **insert_node - inserts a new node at a given position
 *
 *@head: pointer to head nodo to list
 *@number: element to save in n
 *
 *Return: address of the new node or null if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *aux, *sig;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->n = number;
	aux = *head;
	if (aux == NULL)
	{
		node->next = *head;
		*head = node;
		return (*head);
	}
	for (; aux->next != NULL; aux = aux->next)
	{
		if (number < aux->next->n)
		{
			sig = aux->next;
			aux->next = node;
			node->next = sig;
			return (node);
		}
	}
	aux->next = node;
	node->next = NULL;
	return (node);
}
