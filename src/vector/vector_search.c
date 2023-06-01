#include "nlibc/vector.h"

size_t vector_search(Vector const * vector, void const * search, compare_func_t compare_f)
{
	size_t index;
	void * element;

	index = 0;
	while (index < vector->count)
	{
		element = vector_at(vector, index);
 		if (compare_f(search, element) == 0)
			return (index);
		++index;
	}
	return (index);
}

