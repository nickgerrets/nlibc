#include "tester.h"

int	main(void)
{
	test_buffer(); NL;
	test_lists(); NL;
	test_vector(); NL;
	test_macrovector(); NL;
	test_hashmap(); NL;

	test_tokenizer(); NL;

	return (0);
}
