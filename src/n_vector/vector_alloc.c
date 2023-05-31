#include "n_vector.h"

#include <string.h>
#include <assert.h>

t_vector n_vector_create(size_t _sizeof, allocator_t const* allocator)
{
	return (n_vector_create_count(_sizeof, 1, allocator));
}

t_vector n_vector_create_count(size_t _sizeof, size_t count, allocator_t const* allocator)
{
	assert(_sizeof > 0 && count > 0);

	if (allocator == NULL)
		allocator = n_allocator_default();

	return (t_vector) {
		.allocator = *allocator,
		.count = 0,
		.type_size = _sizeof,
		.max_count = count,
		.mem = allocator->alloc_f(_sizeof * count)
	};
}

void n_vector_resize(t_vector *vector, size_t new_count)
{
	assert(vector != NULL && new_count > 0);

	vector->mem = vector->allocator.realloc_f(vector->mem, vector->type_size * new_count);
	vector->max_count = new_count;
	if (vector->count > new_count)
		vector->count = new_count;
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
	
	vector->allocator.freef(vector->mem);
	vector->count = 0;
	vector->max_count = 0;
	vector->mem = NULL;
}
