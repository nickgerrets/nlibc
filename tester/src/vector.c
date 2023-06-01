#include "tester.h"
#include "nlibc/vector.h"
#include <stdlib.h>

static int compare_int(void const * a, void const * b)
{
	return ( *(int *)a - *(int *)b );
}

static void vector_add_one(void * data)
{
	int * n = (int *)data;
	*n += 1;
}

static void put_int(void * data)
{
	printf(" %d ", *(int*)data);
}

void test_vector(void)
{
	LOG("VECTOR TESTS");

	Vector vector = vector_create( sizeof(int), NULL);
	TEST("vector_create()", vector.mem != NULL);

	vector_push_back(&vector, &(int){4});
	TEST("vector_push_back()", DREF(int, vector.mem) == 4);

	{
		int const _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		vector_push_back_array(&vector, _array, sizeof(_array) / sizeof(int));
		TEST("vector_push_back_array()", memcmp(_array, CAST(int*, vector.mem) + 1, sizeof(_array) / sizeof(int)) == 0);
	}

	{
		int const _array[] = {4, 9, 8, 7, 6, 10, 5, 4, 3, 2, 1};
		vector_insert(&vector, &(int){10}, 5);
		TEST("vector_insert()", memcmp(_array, vector.mem, sizeof(_array) / sizeof(int)) == 0);
	}

	{
		int const _array[] = {5, 10, 9, 8, 7, 11, 6, 5, 4, 3, 2};
		vector_iterate(&vector, vector_add_one);
		TEST("vector_iterate()", memcmp(_array, vector.mem, sizeof(_array) / sizeof(int)) == 0);
	}

	vector_pop_back(&vector);
	TEST("vector_pop_back()", *((int*)vector.mem + (vector.count - 1)) == 3 )

	TEST("vector_last()", *(int*)vector_last(&vector) == 3);

	{
		size_t index = vector_search(&vector, &(int){11}, compare_int);
		TEST("vector_search() existing", index == 5);

		index = vector_search(&vector, &(int){89842}, compare_int);
		TEST("vector_search() non-existant", index == vector.count);
	}

	{
		int const _array_sorted[] = {3, 4, 5, 5, 6, 7, 8, 9, 10, 11};
		qsort(
			vector_data(&vector),
			vector_count(&vector),
			vector_type_size(&vector),
			compare_int
		);
		TEST("qsort() on Vector", memcmp(_array_sorted, vector.mem, sizeof(_array_sorted) / sizeof(int)) == 0);
	}

	vector_free(&vector);
}
