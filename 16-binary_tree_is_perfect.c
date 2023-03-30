#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * binary_tree_nodes - Returns count of nodes in a tree
 * Return: returns number of nodes
 */

size_t binary_tree_leaves(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves = binary_tree_leaves(tree);

	size_t perfect = 0;

	if (leaves == 0)
	{
		perfect += binary_tree_is_perfect(tree->left);
		perfect += binary_tree_is_perfect(tree->right);
	}

	return (perfect);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: If the tree is NULL, must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
