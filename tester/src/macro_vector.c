#include "tester.h"
#include "nlibc/macro_vector.h"

void test_macrovector(void)
{
	LOG("MACRO VECTOR TESTS");

	macro_vector_t(int) vector = macro_vector_create(int);
	TEST("macro_vector_create()", vector.mem != NULL);

	macro_vector_t(int) other_vector;

	macro_vector_init(&other_vector);
	TEST("macro_vector_init()", other_vector.mem != NULL);

	macro_vector_free(&other_vector);
	TEST("macro_vector_free()", other_vector.mem == NULL);

	macro_vector_push_back(&vector, 5);
	TEST("macro_vector_push_back()", vector.mem[0] == 5);

	int* x = macro_vector_at(&vector, 0);
	TEST("macro_vector_at()", *x == 5);

	macro_vector_pop_back(&vector);
	TEST("macro_vector_pop_back()", vector.count == 0);

	macro_vector_free(&vector);
}
