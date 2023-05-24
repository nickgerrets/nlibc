#include "n_vector.h"
#include <assert.h>

void n_vector_add(t_vector *vector, void const *data)
{
	n_vector_add_array(vector, data, 1);
}

void n_vector_iterate(t_vector *vector, t_data_f func)
{
	t_byte	*data;
	size_t	i;

	if (!func)
		return ;
	data = vector->mem;
	i = 0;
	while (i < vector->curr_size)
	{
		func((void *)(data + i));
		i += vector->element_size;
	}
}

void *n_vector_at(t_vector *vector, size_t index)
{
	t_byte *data;
	
	assert(index < vector->curr_count);
	data = vector->mem;
	return (data + (index * vector->element_size));
}

void *n_vector_last(t_vector *vector)
{
	assert(vector->curr_count != 0);
	return (n_vector_at(vector, vector->curr_count - 1));
}

// Inserts element at index (if index is within scope)
void n_vector_insert(t_vector *vector, void *data, size_t index)
{
	if (index >= vector->max_count)
		return ;
	if (vector->curr_count == vector->max_count)
		n_vector_resize(vector, vector->curr_count * 2);
	n_memmove((t_byte *)vector->mem + vector->element_size * (index + 1),
		(t_byte *)vector->mem + vector->element_size * index, (vector->curr_count - index + 1) * vector->element_size);
	n_memcpy((t_byte *)vector->mem + vector->element_size * index, data, vector->element_size);
	vector->curr_count += 1;
	vector->curr_size += vector->element_size;
}
