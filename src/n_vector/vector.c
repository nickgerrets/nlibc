#include "n_vector.h"

void n_vector_add(t_vector *vector, void const *data)
{
	n_vector_add_array(vector, data, 1);
}

void n_vector_iterate(t_vector *vector, t_data_iter_f func)
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
	if (index > vector->max_count)
		return (NULL);
	return ((t_byte *)vector->mem + index);
}

// 0   1   2

// Inserts element at index (if index is within scope)
void n_vector_insert(t_vector *vector, void *data, size_t index)
{
	t_byte	b[vector->element_size];
	size_t	cpy_count;

	if (index >= vector->max_count)
		return ;
	// old_count = vector->curr_count;
	// vector->curr_count = index + 1;
	// n_vector_add_array(vector, (t_byte *)vector->mem + vector->element_size * index, old_count - vector->curr_count);
	n_vector_add(vector, b);
	cpy_count = vector->curr_count - index;
	n_memcpy((t_byte *)vector->mem + vector->element_size * index + 1,
		(t_byte *)vector->mem + vector->element_size * index,
		cpy_count);
	n_memcpy((t_byte *)vector->mem + vector->element_size * index, data, vector->element_size);
}
