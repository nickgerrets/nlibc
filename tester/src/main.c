#include "tester.h"

int	main(void)
{
	test_buffer(); NL;
	test_list(); NL;
	test_vector(); NL;
	test_macrovector(); NL;
	test_hashmap(); NL;

	return (0);
}
