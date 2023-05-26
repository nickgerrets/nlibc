#include "n_vector.h"

#include <string.h>

t_vector n_vector_new(size_t _sizeof)
{
	return (n_vector_new_count(_sizeof, 1));
}

t_vector n_vector_new_count(size_t _sizeof, size_t count)
{
	t_vector vector;

	vector.element_size = _sizeof;
	vector.curr_count = 0;
	vector.max_count = count;
	vector.max_size = _sizeof * count;
	vector.curr_size = 0;
	vector.mem = malloc(_sizeof * count);
	if (!vector.mem)
	{
		vector.max_count = 0;
		vector.max_size = 0;
	}
	return (vector);
}

void n_vector_resize(t_vector *vector, size_t new_count)
{
	t_vector	new_vector;
	size_t		count;

	count = new_count;
	if (vector->curr_count < new_count)
		count = vector->curr_count;
	new_vector = n_vector_new_count(vector->element_size, new_count);
	n_vector_add_array(&new_vector, vector->mem, count);
	n_vector_free(vector);
	*vector = new_vector;
}

void n_vector_add_array(t_vector *vector, void const *data, size_t count)
{
	size_t new_max_count;

	if (!data || count == 0)
		return ;
	if (vector->curr_count + count > vector->max_count)
	{
		new_max_count = vector->max_count * 2;
		new_max_count += (new_max_count == 0);
		while (new_max_count < vector->curr_count + count)
			new_max_count *= 2;
		n_vector_resize(vector, new_max_count);
	}
	if (!vector->mem)
	{
		vector->max_count = 0;
		vector->max_size = 0;
		return ;
	}
	memcpy(((t_byte *)vector->mem) + vector->curr_size, data, vector->element_size * count);
	vector->curr_count += count;
	vector->curr_size += vector->element_size * count;
}

void n_vector_free(t_vector *vector)
{
	free(vector->mem);
	vector->curr_count = 0;
	vector->curr_size = 0;
	vector->max_count = 0;
	vector->max_size = 0;
	vector->mem = NULL;
}
