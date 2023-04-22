#include "n_list.h"

t_list	*n_list_new(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	return (list);
}

void	n_list_free(t_list *head, t_data_f del_func)
{
	t_list *del;

	while (head)
	{
		del_func(head->content);
		del = head;
		head = head->next;
		free(del);
	}
}

t_list	*n_list_prev(t_list *head, t_list *element)
{
	t_list *prev;

	prev = head;
	while (prev && prev->next != element)
		prev = prev->next;
	return (prev);
}

void	n_list_delete_element(t_list **head, t_list *element, t_data_f del_func)
{
	t_list *prev;

	prev = n_list_prev(*head, element);
	if (!prev)
		return ;
	prev->next = prev->next->next;
	del_func(element->content);
	free(element);
}
