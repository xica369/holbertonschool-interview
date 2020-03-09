#include "lists.h"


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
int *grid, cont, cont1, cont2;
listint_t *temp;

if (*head == NULL)
	return (1);

temp = *head;
grid = malloc(sizeof(int));
if (grid == NULL)
{
	free(grid);
	return (0);
}
grid[0] = temp->n;
temp = temp->next;

for (cont = 1; temp != '\0'; temp = temp->next, cont++)
{
	grid = realloc(grid, (cont + 1) * sizeof(int));
	if (grid == NULL)
	{
		free(grid);
		return (0);
	}
	grid[cont] = temp->n;
}
for (cont1 = 0, cont2 = cont - 1; cont1 < cont; cont1++, cont2--)
{
	if (grid[cont1] != grid[cont2])
	{
		free(grid);
		return (0);
	}
}
free(grid);
return (1);
}
