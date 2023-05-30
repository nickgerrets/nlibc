#include "n_vector.h"

size_t n_vector_search(t_vector const * vector, void const * search, t_compare_data_f compare_f)
{
	size_t index;
	void * element;

	index = 0;
	while (index < vector->count)
	{
		element = n_vector_at(vector, index);
 		if (compare_f(search, element) == 0)
			return (index);
		++index;
	}
	return (index);
}

