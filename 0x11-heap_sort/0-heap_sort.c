#include "sort.h"

/**
 * heap - find the largest number in a heap level
 *
 * @array: array of integers
 * @size_max: maximum size in each iteration
 * @size: original array size
 * @idx: root index
 */
void heap(int *array, size_t size_max, size_t size, size_t idx)
{
	size_t max, left, right;
	int value;

	max = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < size_max && array[left] > array[max])
		max = left;

	if (right < size_max && array[right] > array[max])
		max = right;

	if (max != idx)
	{
		value = array[idx];
		array[idx] = array[max];
		array[max] = value;
		print_array(array, size);

		heap(array, size_max, size, max);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order Heap sort
 *
 * @array: array of integers to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int aux, first;

	if (!array || size < 1)
		return;
	for (aux = size / 2 - 1; aux >= 0; aux--)
		heap(array, size, size, aux);

	for (aux = size - 1; aux > 0; aux--)
	{
		first = array[0];
		array[0] = array[aux];
		array[aux] = first;
		print_array(array, size);
		heap(array, aux, size, 0);
	}
}
