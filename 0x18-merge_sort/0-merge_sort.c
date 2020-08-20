#include "sort.h"

/**
 *merge - Merges two subarrays of integer
 *
 *@array: array of integers
 *@R: raight subarry
 *@L: left subarry
 *@size: size of array
 *
 */
void merge(int *array, int *R, int *L, size_t size)
{
	int i = 0, j = 0, k = 0;
	int l_cont = size / 2, r_cont = size - l_cont;

	while (i < l_cont && j < r_cont)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < l_cont)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < r_cont)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, l_cont);
	printf("[right]: ");
	print_array(R, r_cont);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 *merge_sort - sorts an array of integers in ascending order with Merge Sort
 *
 *@array: array of integer to sort
 *@size: size of array
 *
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2, index;
	int R[300], L[300];

	if (size < 2 || array == NULL)
		return;

	for (index = 0; index < middle; index++)
		L[index] = array[index];

	for (index = middle;  index < size; index++)
		R[index - middle] = array[index];

	merge_sort(L, middle);
	merge_sort(R, size - middle);
	merge(array, R, L, size);
}
