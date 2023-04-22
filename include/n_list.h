#ifndef N_LIST_H
# define N_LIST_H

# include <stdlib.h>

# include "n_common.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif // N_LIST_H
