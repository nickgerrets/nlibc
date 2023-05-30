#include "n_tree.h"

t_tree_node *n_tree_node_create(void *content)
{
	t_tree_node *node;

	node = malloc(sizeof(t_tree_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->branches = NULL;
	return (node);
}

t_tree_node *n_tree_node_add_branch_front(t_tree_node *node, t_tree_node *branch)
{
	return (n_list_push_front(&(node->branches), n_list_create(branch))->content);
}

t_tree_node *n_tree_node_add_branch_back(t_tree_node *node, t_tree_node *branch)
{
	return (n_list_push_back(&(node->branches), n_list_create(branch))->content);
}

void	n_tree_iterate(t_tree_node *head, t_data_f func)
{
	t_list *branch;

	func(head->content);
	branch = head->branches;
	while (branch)
	{
		n_tree_iterate(branch->content, func);
		branch = branch->next;
	}
}

void	n_tree_free(t_tree_node *head, t_data_f free_func)
{
	t_list *branch;

	free_func(head->content);
	branch = head->branches;
	while (branch)
	{
		n_tree_free(branch->content, free_func);
		branch = branch->next;
	}
	n_list_free(head->branches, NULL);
	free(head);
}
