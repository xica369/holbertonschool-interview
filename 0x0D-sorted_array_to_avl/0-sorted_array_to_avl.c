#include "binary_trees.h"

/**
 *create_binary_tree - function that builds an AVL tree from an array
 *
 *@array: pointer to the first element of the array to be converted
 *@size: number of element in the array
 *@parent: pointer to parent of the new node
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *create_binary_tree(int *array, size_t size, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	if (size == 1):
		
}

/**
 *sorted_array_to_avl - function that builds an AVL tree from an array
 *
 *@array: pointer to the first element of the array to be converted
 *@size: number of element in the array
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (size == 0)
		return (NULL);

	if (array == 0)
		return (NULL);

	root = create_binary_tree(array, size, NULL);

	return (root);
}
