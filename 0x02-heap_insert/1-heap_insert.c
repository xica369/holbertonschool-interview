#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 *@root: is a double pointer to the root node of the Heap
 *@value: is the value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *nodo;

	if (!root)
	{
		return (NULL);
	}
	nodo = calloc(1, sizeof(heap_t));
	if (nodo == NULL)
	{
		return (NULL);
	}
	nodo->n = value;
	nodo->left = NULL;
	nodo->right = NULL;
	nodo->parent = *root;
	if (*root == NULL)
	{
		*root = nodo;
	}

	return (nodo);
}
