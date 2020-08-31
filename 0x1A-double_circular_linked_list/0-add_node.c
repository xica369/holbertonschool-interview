#include "list.h"

/**
 *add_node_end - Add a new node to the end of a double circular linked list
 *
 *@list: the list to modify
 *@str: the string to copy into the new node
 *
 *Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last_node, *temp;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str;

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;

		return (new_node);
	}

	temp = *list;
	last_node = temp->prev;

	last_node->next = new_node;
	new_node->next = temp;
	new_node->prev = last_node;
	temp->prev = new_node;

	return (new_node);
}

/**
 *add_node_begin - Add a new node to the begin of a double circular linked list
 *
 *@list: the list to modify
 *@str: the string to copy into the new node
 *
 *Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last_node, *temp;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str;

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;

		return (new_node);
	}

	temp = *list;
	last_node = temp->prev;

	new_node->next = temp;
	new_node->prev = last_node;
	temp->prev = last_node->next = new_node;
	*list = new_node;

	return (new_node);
}
