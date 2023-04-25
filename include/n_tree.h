#ifndef TREE_H
# define TREE_H

# include "n_list.h"

typedef struct s_tree_node t_tree_node;
struct s_tree_node
{
	void*	content;
	t_list* branches;
};

t_tree_node *n_tree_node_new(void *content);
t_tree_node *n_tree_node_add_branch_front(t_tree_node *node, t_tree_node *branch);
t_tree_node *n_tree_node_add_branch_back(t_tree_node *node, t_tree_node *branch);
void		n_tree_iterate(t_tree_node *head, t_data_f func);
void		n_tree_free(t_tree_node *head, t_data_f free_func);

#endif // TREE_H
