#include "n_vector.h"

#include <string.h>
#include <assert.h>

t_vector n_vector_create(size_t _sizeof, void* (*allocator)(size_t))
{
	return (n_vector_create_count(_sizeof, 1, allocator));
}

t_vector n_vector_create_count(size_t _sizeof, size_t count, void* (*allocator)(size_t))
{
	assert(_sizeof > 0 && count > 0);

	if (allocator == NULL)
		allocator = malloc;

	return (t_vector) {
		.allocator = allocator,
		.count = 0,
		.type_size = _sizeof,
		.max_count = count,
		.mem = allocator(_sizeof * count)
	};
}

void n_vector_resize(t_vector *vector, size_t new_count)
{
	t_vector	new_vector;
	size_t		count;

	count = new_count;
	if (vector->count < new_count)
		count = vector->count;
	new_vector = n_vector_create_count(vector->type_size, new_count, vector->allocator);
	n_vector_push_back_array(&new_vector, vector->mem, count);
	n_vector_free(vector);
	*vector = new_vector;
}

void n_vector_push_back_array(t_vector *vector, void const *data, size_t count)
{
	assert(vector != NULL && data != NULL);

	if (vector->count + count > vector->max_count)
	{
		size_t new_max = vector->max_count * N_VECTOR_GROWTH_FACTOR;
		while (new_max < vector->count + count)
			new_max *= N_VECTOR_GROWTH_FACTOR;
		n_vector_resize(vector, new_max);
	}
	
	if (vector->mem == NULL)
		return ;

	memcpy((t_byte*)vector->mem + n_vector_size(vector), data, vector->type_size * count);
	vector->count += count;
}

void n_vector_free(t_vector *vector)
{
	assert(vector != NULL);
	
	free(vector->mem);
	vector->count = 0;
	vector->max_count = 0;
	vector->mem = NULL;
}
