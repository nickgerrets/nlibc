#include "nlibc/list.h"

List* list_create(void* content)
{
	List * list = malloc(sizeof(List));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void list_free(List* head, data_func_t del_func)
{
	while (head)
	{
		if (del_func)
			del_func(head->content);
		List * del = head;
		head = head->next;
		free(del);
	}
}

List* list_prev(List const* head, List const* element)
{
	List const* prev = head;
	while (prev && prev->next != element)
		prev = prev->next;
	return ((List*)prev);
}

void list_delete_element(List** head, List* element, data_func_t del_func)
{
	List* prev = list_prev(*head, element);
	if (!prev)
		return ;
	prev->next = prev->next->next;
	del_func(element->content);
	free(element);
}
