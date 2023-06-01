#include "nlibc/vector.h"

#include <string.h>
#include <assert.h>

Vector vector_create(size_t _sizeof, Allocator const* allocator)
{
	return (vector_create_count(_sizeof, 1, allocator));
}

Vector vector_create_count(size_t _sizeof, size_t count, Allocator const* allocator)
{
	assert(_sizeof > 0 && count > 0);

	if (allocator == NULL)
		allocator = allocator_default();

	return (Vector) {
		.allocator = *allocator,
		.count = 0,
		.type_size = _sizeof,
		.max_count = count,
		.mem = allocator->alloc_f(_sizeof * count)
	};
}

void vector_resize(Vector *vector, size_t new_count)
{
	assert(vector != NULL && new_count > 0);

	vector->mem = vector->allocator.realloc_f(vector->mem, vector->type_size * new_count);
	vector->max_count = new_count;
	if (vector->count > new_count)
		vector->count = new_count;
}

void vector_push_back_array(Vector *vector, void const *data, size_t count)
{
	assert(vector != NULL && data != NULL);

	if (vector->count + count > vector->max_count)
	{
		size_t new_max = vector->max_count * VECTOR_GROWTH_FACTOR;
		while (new_max < vector->count + count)
			new_max *= VECTOR_GROWTH_FACTOR;
		vector_resize(vector, new_max);
	}
	
	if (vector->mem == NULL)
		return ;

	memcpy((byte_t*)vector->mem + vector_size(vector), data, vector->type_size * count);
	vector->count += count;
}

void vector_free(Vector *vector)
{
	assert(vector != NULL);
	
	vector->allocator.freef(vector->mem);
	vector->count = 0;
	vector->max_count = 0;
	vector->mem = NULL;
}
