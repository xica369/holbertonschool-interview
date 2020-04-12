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
	size_t pos1 = 0, pos2 = 1, temp1, temp2, aux1, flag = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_RIGHT)
	{       pos1 = size - 1;
		pos2 = size - 2; }
	for (temp1 = 0; temp1 < size; temp1++)
	{       aux1 = pos2;
		flag = 0;
		for (temp2 = temp1 + 1; temp2 < size; temp2++)
		{
			if (line[pos1] != 0 && line[pos2] == line[pos1])
			{	line[pos1] = line[pos1] * 2;
				line[pos2] = 0;
				break; }

			if (line[pos1] == 0 && line[pos2] != 0)
			{	line[pos1] = line[pos2];
				line[pos2] = 0;
				flag = 1;
				pos2 = aux1;
				temp1--;
				break; }

			if (line[pos2] != 0)
				break;

			direction == SLIDE_LEFT ? pos2++ : pos2--;
		}
		if (line[pos1] == 0)
			break;
		if (direction == SLIDE_LEFT && flag == 0)
		{	pos1++;
			pos2 = pos1 + 1; }
		if (direction == SLIDE_RIGHT && flag == 0)
		{	pos1--;
			pos2 = pos1 - 1; }
	}
	return (1);
}
