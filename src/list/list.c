#include "nlibc/list.h"

List* list_last(List* list)
{
	while (list->next)
		list = list->next;
	return (list);
}

List* list_push_front(List** dst_head, List* src_head)
{
	if (!src_head)
		return (NULL);
	if (!*dst_head)
	{
		*dst_head = src_head;
		return (src_head);
	}
	List* head = src_head;
	src_head = list_last(src_head);
	src_head->next = *dst_head;
	*dst_head = head;
	return (src_head);
}

List* list_push_back(List** dst_head, List* src_head)
{
	if (!*dst_head)
	{
		*dst_head = src_head;
		return (src_head);
	}
	list_last(*dst_head)->next = src_head;
	return (src_head);
}

List* list_insert(List* prev, List* new)
{
	List* next = prev->next;
	prev->next = new;
	new->next = next;
	return (new);
}

size_t list_count(List const* list)
{
	size_t count = 0;
	while (list)
	{
		list = list->next;
		++count;
	}
	return (count);
}

void list_iterate(List* head, list_func_t func)
{
	while (head)
	{
		func(head);
		head = head->next;
	}
}
