#ifndef LIST_H
# define LIST_H

# include "common.h"

# include <stdlib.h>

typedef struct s_list List;
struct s_list
{
	void *content;
	List *next;
};

typedef void (*list_func_t)(List*);

// list_alloc.
List* list_create(void* content);
void	list_free(List* head, data_func_t del_func /* can be NULL*/ );
List* list_prev(List const* head, List const* element);
void	list_delete_element(List** head, List* element, data_func_t del_func);

// list.c
List* list_last(List* list);
List* list_push_front(List** dst_head, List* src_head);
List* list_push_back(List** dst_head, List* src_head);
List* list_insert(List* prev, List* new_);
size_t	list_count(List const* list);
void	list_iterate(List* head, list_func_t func);


#endif // LIST_H
