#include "tester.h"
#include "macro_vector.h"

void test_macrovector(void)
{
	LOG("MACRO-ED VECTOR TESTS");

	// vector_t(int) vector;
	vector_t(int) vector_c = vector_create(int);

	vector_init(&vector);
	TEST("vector_init()", vector.mem != NULL);

	vector_push_back(&vector, 5);
	TEST("vector_push_back()", vector.mem[0] == 5);

	
}
