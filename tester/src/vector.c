#include "n_vector.h"
#include "tester.h"

static int vector_compare_int(void const * a, void const * b)
{
	return ( *(int *)a - *(int *)b );
}

static void vector_add_one(void * data)
{
	int * n = (int *)data;
	*n += 1;
}

void test_vector(void)
{
	LOG("VECTOR TESTS");

	t_vector vector = n_vector_create( sizeof(int), NULL);
	TEST("n_vector_create()", vector.mem != NULL);

	n_vector_push_back(&vector, &(int){4});
	TEST("n_vector_push_back()", DREF(int, vector.mem) == 4);

	{
		int const _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		n_vector_push_back_array(&vector, _array, sizeof(_array) / sizeof(int));
		TEST("n_vector_push_back_array()", memcmp(_array, CAST(int*, vector.mem) + 1, sizeof(_array) / sizeof(int)) == 0);
	}

	{
		int const _array[] = {4, 9, 8, 7, 6, 10, 5, 4, 3, 2, 1};
		n_vector_insert(&vector, &(int){10}, 5);
		TEST("n_vector_insert()", memcmp(_array, vector.mem, sizeof(_array) / sizeof(int)) == 0);
	}

	{
		int const _array[] = {5, 10, 9, 8, 7, 11, 6, 5, 4, 3, 2};
		n_vector_iterate(&vector, vector_add_one);
		TEST("n_vector_iterate()", memcmp(_array, vector.mem, sizeof(_array) / sizeof(int)) == 0);
	}

	n_vector_pop_back(&vector);
	TEST("n_vector_pop_back()", *((int*)vector.mem + (vector.count - 1)) == 3 )

	TEST("n_vector_last()", *(int*)n_vector_last(&vector) == 3);

	{
		size_t index = n_vector_search(&vector, &(int){11}, vector_compare_int);
		TEST("n_vector_search() existing", index == 5);

		index = n_vector_search(&vector, &(int){89842}, vector_compare_int);
		TEST("n_vector_search() non-existant", index == vector.count);
	}

	n_vector_free(&vector);

	// NL; {
	// 	int _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	// 	printf("n_vector_create() of int\n");
	// 	t_vector vector = n_vector_create(sizeof(int));

	// 	printf("n_vector_push_back() 4, 5 and 6\n");
	// 	n_vector_push_back(&vector, &(int){4});
	// 	n_vector_push_back(&vector, &(int){5});
	// 	n_vector_push_back(&vector, &(int){6});

	// 	printf("n_vector_push_back_array() 9 to 1\n");
	// 	n_vector_push_back_array(&vector, _array, sizeof(_array) / sizeof(int));

	// 	printf("n_vector_insert() 666 at position 2\n");
	// 	n_vector_insert(&vector, &(int){666}, 2);

	// 	printf("n_vector_iterate() with put digit:\n");
	// 	IND; n_vector_iterate(&vector, vector_add_one); NL;
	// 	printf("vector count / max_count: %lu/%lu\n", vector.count, vector.max_count);


	// 	printf("n_vector_search() for '5':\n");
	// 	void * found = n_vector_search(&vector, &(int){5}, vector_compare_int);
	// 	if (!found)
	// 		printf("5 not found!\n");
	// 	else
	// 		printf("%d was found\n", *(int *)found);

	// 	printf("n_vector_free()\n");
	// 	n_vector_free(&vector);
	// }
}