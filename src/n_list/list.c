#include "n_list.h"

t_list	*n_list_last(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	n_list_push_front(t_list **dst_head, t_list *src_head)
{
	t_list	*head;

	if (!*dst_head)
	{
		*dst_head = src_head;
		return ;
	}
	head = src_head;
	src_head = n_list_last(src_head);
	src_head->next = *dst_head;
	*dst_head = head;
}

void	n_list_push_back(t_list **dst_head, t_list *src_head)
{
	if (!*dst_head)
	{
		*dst_head = src_head;
		return ;
	}
	n_list_last(*dst_head)->next = src_head;
}

void	n_list_insert(t_list *prev, t_list *new)
{
	t_list *next;

	next = prev->next;
	prev->next = new;
	new->next = next;
}

size_t	n_list_count(t_list *list)
{
	size_t count;

	count = 0;
	while (list->next)
	{
		list = list->next;
		++count;
	}
	return (count);
}

void	n_list_iterate(t_list *head, t_data_f func)
{
	while (head)
	{
		func(head->content);
		head = head->next;
	}
}
