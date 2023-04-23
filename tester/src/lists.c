#include "tester.h"

#include <stdio.h>

static void list_print(t_list *element)
{
	printf("(%d)->", *(int *)element->content);
	if (!element->next)
		printf("NULL");
}

void tester_lists(void)
{
	NL; {
		int _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		t_list *list;

		list = NULL;
		// t_vector int_vec = n_vector_new(sizeof(int));
		// n_vector_add_array(&int_vec, _array, sizeof(_array) / sizeof(int));

		n_putstr_endl("n_list_push_front() an entire array");
		for (size_t i = 0; i < sizeof(_array) / sizeof(int); ++i)
			n_list_push_front(&list, n_list_new(_array + i));
		n_putstr_endl("n_list_iterate() to print it out:");
		IND; n_list_iterate(list, list_print); printf("\n");

		n_list_free(list, NULL);

	}
}
