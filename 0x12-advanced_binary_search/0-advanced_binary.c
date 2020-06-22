#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the index where value is located else -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);

	
}

int search(int *array, size_t start, size_t end, int value)
{
	int iter;
	size_t index;

	printf("Searching in array: %d", array[0]);
	for (iter = start; iter < end; iter++)
		printf(", %d", array[iter]);
	printf("\n");

	index = (start + end) / 2;

	if (array[index] == value)
		return (index);

	if (index == 0)

	if (array[index] > value)
		search(array, index + 1, end, value);

	else
		search(array, start, index - 1, value);
}
