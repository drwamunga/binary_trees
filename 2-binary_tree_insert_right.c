#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a nodeas the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Data stored in node
 *
 * Return: Pointer to the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;
	binary_tree_t *tmp;

	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL || parent == NULL)
		return (NULL);

	right_node->parent = parent;
	right_node->n = value;

	if (!parent->right)
		parent->right = right_node;
	else
	{
		tmp = parent->right;
		parent->right = right_node;
		right_node->right = tmp;
		right_node->right->parent = right_node;
	}

	return (right_node);
}