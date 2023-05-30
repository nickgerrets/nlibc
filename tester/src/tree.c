#include "tester.h"

static void put_tree_data(void *data)
{
	if (!data)
	{
		n_putstr_endl("NULL");
		return ;
	}
	n_putstr_endl(data);
}

void tester_tree(void)
{
	NL; {
		char *str = "HEAD";
		t_tree_node* tree = n_tree_node_create(n_memdup(str, 1 + sizeof(char) * n_strlen(str)));

		str = "\tCHILD1";
		t_tree_node* child = n_tree_node_add_branch_back( tree,
			n_tree_node_create(
				n_memdup(str, 1 + sizeof(char) * n_strlen(str))
			)
		);
		{
			str = "\t\tCHILD1";
			n_tree_node_add_branch_back( child,
				n_tree_node_create(
					n_memdup(str, 1 + sizeof(char) * n_strlen(str))
				)
			);
			str = "\t\tCHILD2";
			n_tree_node_add_branch_back( child,
				n_tree_node_create(
					n_memdup(str, 1 + sizeof(char) * n_strlen(str))
				)
			);
		}

		str = "\tCHILD2";
		n_tree_node_add_branch_back( tree,
			n_tree_node_create(
				n_memdup(str, 1 + sizeof(char) * n_strlen(str))
			)
		);

		str = "\tCHILD3";
		n_tree_node_add_branch_back( tree,
			n_tree_node_create(
				n_memdup(str, 1 + sizeof(char) * n_strlen(str))
			)
		);

		n_tree_iterate(tree, put_tree_data);

		// Free
		// n_tree_iterate(tree, free);
		n_tree_free(tree, free);
	}
}
