#include "tester.h"
#include "macro_vector.h"

VECTOR_CREATE(int);

void test_macrovector(void)
{
	LOG("MACRO-ED VECTOR TESTS");

	// vector_t(int) vector;

	// vector_init(&vector);
	// TEST("vector_init()", vector.mem != NULL);

	

	VECTOR(int) vec_int;

	// VECTOR_INIT(&vec_int);

	// VECTOR_INIT(vec_int);

	// TYPEOF(vec_int)

	__typeof__(int) a;

	a = 4;
	

	vector_init_int(&vec_int);
	TEST("VECTOR_INIT()", vec_int.data != NULL);

	// VECTOR_ADD(vec_int, 5);
	vector_add_int(&vec_int, 5);
	TEST("VECTOR_ADD()", vec_int.data[0] == 5);

	
}
