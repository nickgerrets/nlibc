#include "n_vector.h"

void *n_vector_search(t_vector * vector, void * search, t_compare_data_f compare_f)
{
	size_t index;
	void * element;

	index = 0;
	while (index < vector->curr_count)
	{
		element = n_vector_at(vector, index);
 		if (compare_f(search, element) == 0)
			return (element);
		++index;
	}
	return (NULL);
}

