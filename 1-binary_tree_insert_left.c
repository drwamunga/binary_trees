#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to node to insert the left-child in
 * @value: Value to be stored into the created node
 *
 * Return: Pointer to created node, NULL on failure or if @parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;
	binary_tree_t *tmp;

	left_node = malloc(sizeof(binary_tree_t));
	if ((left_node == NULL) || (parent == NULL))
		return (NULL);

	left_node->parent = parent;
	left_node->n = value;

	if (!parent->left)
		parent->left = left_node;
	else
	{
		tmp = parent->left;
		parent->left = left_node;
		left_node->left = tmp;
		left_node->left->parent = left_node;
	}

	return (left_node);
}