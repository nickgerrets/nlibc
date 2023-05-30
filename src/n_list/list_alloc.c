#include "n_list.h"

t_list* n_list_create(void* content)
{
	t_list * list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void n_list_free(t_list* head, t_data_f del_func)
{
	while (head)
	{
		if (del_func)
			del_func(head->content);
		t_list * del = head;
		head = head->next;
		free(del);
	}
}

t_list* n_list_prev(t_list const* head, t_list const* element)
{
	t_list const* prev = head;
	while (prev && prev->next != element)
		prev = prev->next;
	return ((t_list*)prev);
}

void n_list_delete_element(t_list** head, t_list* element, t_data_f del_func)
{
	t_list* prev = n_list_prev(*head, element);
	if (!prev)
		return ;
	prev->next = prev->next->next;
	del_func(element->content);
	free(element);
}
