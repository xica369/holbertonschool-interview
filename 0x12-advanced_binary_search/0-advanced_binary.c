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

	return (search(array, 0, size, value));
}

/**
 * search - searches for a value in sorted array of integers
 *
 *@array: is a pointer to the first element of the array to search in
 *@start: index to start the subarray
 *@end: index to end the subarray
 *@value: value to search for
 *
 *Return: the index where value is located else -1
 */
int search(int *array, size_t start, size_t end, int value)
{
	size_t iter;
	size_t index;

	if (start == end)
		return (-1);

	printf("Searching in array: ");
	for (iter = start; iter < end; iter++)
	{
		printf("%d", array[iter]);
		if (iter < end - 1)
			printf(", ");
	}
	printf("\n");

	index = (start + end - 1) / 2;

	if (array[index] == value)
	{
		if (array[index - 1] < value)
			return (index);
		else
			return (search(array, start, index + 1, value));
	}

	if (array[index] < value)
	{
		return (search(array, index + 1, end, value));
	}

	if (array[index] > value)
	{
		return (search(array, start, index + 1, value));
	}

	return (-1);
}
