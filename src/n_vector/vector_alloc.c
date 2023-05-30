#include "n_vector.h"

#include <string.h>
#include <assert.h>

t_vector n_vector_create(size_t _sizeof)
{
	return (n_vector_create_count(_sizeof, 1));
}

t_vector n_vector_create_count(size_t _sizeof, size_t count)
{
	t_vector vector;

	vector.type_size = _sizeof;
	vector.count = 0;
	vector.max_count = count;
	vector.mem = malloc(_sizeof * count);
	if (!vector.mem)
		vector.max_count = 0;
	return (vector);
}

void n_vector_resize(t_vector *vector, size_t new_count)
{
	t_vector	new_vector;
	size_t		count;

	count = new_count;
	if (vector->count < new_count)
		count = vector->count;
	new_vector = n_vector_create_count(vector->type_size, new_count);
	n_vector_push_back_array(&new_vector, vector->mem, count);
	n_vector_free(vector);
	*vector = new_vector;
}

void n_vector_push_back_array(t_vector *vector, void const *data, size_t count)
{
	size_t new_max_count;

	assert(data != NULL);

	if (vector->count + count > vector->max_count)
	{
		size_t new_max = vector->max_count * N_VECTOR_GROWTH_FACTOR;
		while (new_max < vector->count + count)
			new_max *= N_VECTOR_GROWTH_FACTOR;
		n_vector_resize(vector, new_max);
	}
	
	assert(vector->mem != NULL);

	memcpy((t_byte*)vector->mem + n_vector_size(vector), data, vector->type_size * count);
	vector->count += count;
}

void n_vector_free(t_vector *vector)
{
	free(vector->mem);
	vector->count = 0;
	vector->max_count = 0;
	vector->mem = NULL;
}
