#include "tester.h"

static void list_print(List *element)
{
	printf("(%d)->", *(int *)element->content);
	if (!element->next)
		printf("NULL");
}

void test_list(void)
{
	LOG("LIST TESTS");

	struct s_item { int x, y; };

	struct s_item item1 = {1, 5};
	List* list = list_create(&item1);
	TEST("list_create()", list != NULL && ((struct s_item*)list->content)->x == 1);

	struct s_item item2 = {2, 5};
	list_push_front(&list, list_create(&item2));
	TEST("list_push_front()", ((struct s_item*)list->content)->x == 2);

	struct s_item item3 = {3, 1};
	list_push_back(&list, list_create(&item3));
	TEST("list_push_back()", ((struct s_item*)list->next->next->content)->x == 3);

	TEST("list_count()", list_count(list) == 3);

	struct s_item item4 = {4, 1};
	list_insert(list, list_create(&item4));
	TEST("list_insert()",
		((struct s_item*)list->content)->x == 2
		&& ((struct s_item*)list->next->content)->x == 4
		&& ((struct s_item*)list->next->next->content)->x == 1
	);

	TEST("list_last()", ((struct s_item*)list_last(list)->content)->x == 3);

	list_free(list, NULL);
}
