#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integers
 *
 * @line: array of ints containing size elements, that must be slidued & merged
 * @size: size elements
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t cont1 = 0, cont2 = 1, tem1 = 0, tem2, aux1 = 0, aux2, flag = 0;

	if (validate(line, size, direction) == 0)
		return (0);
	if (direction == SLIDE_RIGHT)
	{	cont1 = size - 1;
		cont2 = size - 2; }
	while (tem1 < size)
	{	tem2 = aux1 + 1;
		aux2 = cont2;
		flag = 0;
		while (tem2 <= size)
		{
			if (line[cont1] != 0 && line[cont2] == line[cont1])
			{	line[cont1] = line[cont1] * 2;
				line[cont2] = 0;
				break; }
			if (line[cont1] == 0 && line[cont2] != 0)
			{	line[cont1] = line[cont2];
				line[cont2] = 0;
				flag = 1;
				cont2 = aux2;
				aux1--;
				break; }
			if (direction == SLIDE_RIGHT)
				cont2--;
			if (direction == SLIDE_LEFT)
				cont2++;
			tem2++; }
		if (line[cont1] == 0)
			break;
		if (direction == SLIDE_LEFT && flag == 0)
		{	cont1++;
			cont2 = cont1 + 1; }
		if (direction == SLIDE_RIGHT && flag == 0)
		{	cont1--;
			cont2 = cont1 - 1; }
		tem1++;
		aux1++; }
	return (1);
}

/**
 * validate - function that validate the list and the direction
 *
 * @line: array of ints containing size elements, that must be slidued & merged
 * @size: size elements
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */

int validate(int *line, size_t size, int direction)
{
	size_t cont;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (cont = 0; cont < size; cont++)
	{
		if (line[0] != 0)
			return (1);
	}

	return (0);
}
