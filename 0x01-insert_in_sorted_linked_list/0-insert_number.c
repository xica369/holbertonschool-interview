#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 **insert_nodeint_at_index - inserts a new node at a given position
 *
 *@head: pointer to head nodo to list
 *@idx: index of the list where the new node should be added
 *@number: element to save in n
 *
 *Return: address of the new node or null if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *aux, *sig;
	int cont = 0, num_next, num_n_next;

	node = malloc(sizeof(listint_t));

	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->n = n;
	aux = *head;

	if (aux == NULL)
	{
		
	}	

	for (; aux != NULL; aux = aux->next)
	{
		if 
		if (aux->next->next
	}
}
