#ifndef N_LIST_H
# define N_LIST_H

# include "n_common.h"

# include <stdlib.h>

typedef struct s_list t_list;
struct s_list
{
	void			*content;
	struct s_list	*next;
};

typedef void (*t_list_f)(t_list *);

// list_alloc.
t_list* n_list_create(void* content);
void	n_list_free(t_list* head, t_data_f del_func /* can be NULL*/ );
t_list* n_list_prev(t_list const* head, t_list const* element);
void	n_list_delete_element(t_list** head, t_list* element, t_data_f del_func);

// list.c
t_list* n_list_last(t_list* list);
t_list* n_list_push_front(t_list** dst_head, t_list* src_head);
t_list* n_list_push_back(t_list** dst_head, t_list* src_head);
t_list* n_list_insert(t_list* prev, t_list* new_);
size_t	n_list_count(t_list const* list);
void	n_list_iterate(t_list* head, t_list_f func);


#endif // N_LIST_H
