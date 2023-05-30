#include "tester.h"

static void list_print(t_list *element)
{
	printf("(%d)->", *(int *)element->content);
	if (!element->next)
		printf("NULL");
}

void test_lists(void)
{
	LOG("LIST TESTS");

	struct s_item { int x, y; };

	struct s_item item1 = {1, 5};
	t_list* list = n_list_create(&item1);
	TEST("n_list_create()", list != NULL && ((struct s_item*)list->content)->x == 1);

	struct s_item item2 = {2, 5};
	n_list_push_front(&list, n_list_create(&item2));
	TEST("n_list_push_front()", ((struct s_item*)list->content)->x == 2);

	struct s_item item3 = {3, 1};
	n_list_push_back(&list, n_list_create(&item3));
	TEST("n_list_push_back()", ((struct s_item*)list->next->next->content)->x == 3);

	TEST("n_list_count()", n_list_count(list) == 3);

	struct s_item item4 = {4, 1};
	n_list_insert(list, n_list_create(&item4));
	TEST("n_list_insert()",
		((struct s_item*)list->content)->x == 2
		&& ((struct s_item*)list->next->content)->x == 4
		&& ((struct s_item*)list->next->next->content)->x == 1
	);

	TEST("n_list_last()", ((struct s_item*)n_list_last(list)->content)->x == 3);

	n_list_free(list, NULL);
}
