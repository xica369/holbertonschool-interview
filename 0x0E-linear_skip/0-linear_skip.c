#include "search.h"

/**
 * linear_skip - Linear search in a skip list
 *
 * @list: pointer to the head of the skip list to search in
 * @value: is the value to search for
 *
 * Return: a pointer on the first node where value is located else NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip = list->express;

	if (!list)
		return (NULL);

	printf("Value checked at index [%lu] = [%d]\n",
	       skip->index, skip->n);

	/* search for the value in express */
	while (skip && skip->n < value)
	{
		list = skip;
		skip = skip->express;
		if (!skip)
		{
			/* return to the previous position of express */
			skip = list;

			/* search for the last index */
			while (skip->next)
				skip = skip->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n",
		       skip->index, skip->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       list->index, skip->index);

	/* search for the value in the list from the last position of skip */
	for (; list && list->n <= skip->n; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       list->index, list->n);

		if (list->n == value)
			return (list);
	}
	return (NULL);
}
