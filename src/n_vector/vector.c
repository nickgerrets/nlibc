#include "n_vector.h"
#include <assert.h>
#include <string.h>

void n_vector_push_back(t_vector *vector, void const *data)
{
	n_vector_push_back_array(vector, data, 1);
}

void n_vector_pop_back(t_vector *vector)
{
	assert(vector != NULL);

	if (vector->count > 0)
		--(vector->count);
}

void n_vector_iterate(t_vector* vector, t_data_f func)
{
	assert(vector != NULL && func != NULL);

	t_byte* data = vector->mem;
	size_t i = 0;
	while (i < vector->count)
	{
		func( (void *)(data + (i * vector->type_size)) );
		++i;
	}
}

void* n_vector_at(t_vector const* vector, size_t index)
{
	assert(vector != NULL && index < vector->count);

	return ((t_byte*)vector->mem + (index * vector->type_size));
}

void* n_vector_last(t_vector const* vector)
{
	assert(vector != NULL);
	
	if (vector->count == 0)
		return (NULL);
	return (n_vector_at(vector, vector->count - 1));
}

size_t n_vector_count(t_vector const* vector)
{
	assert(vector != NULL);
	
	return (vector->count);
}

size_t n_vector_max_count(t_vector const* vector)
{
	assert(vector != NULL);

	return (vector->max_count);
}

size_t n_vector_size(t_vector const* vector)
{
	assert(vector != NULL);

	return (vector->count * vector->type_size);
}

size_t n_vector_max_size(t_vector const* vector)
{
	assert(vector != NULL);

	return (vector->max_count * vector->type_size);
}

size_t n_vector_type_size(t_vector const* vector)
{
	assert(vector != NULL);

	return (vector->type_size);
}

void* n_vector_data(t_vector const* vector)
{
	assert(vector != NULL);

	return (vector->mem);
}

// Inserts element at index (if index is within scope)
void n_vector_insert(t_vector* vector, void* data, size_t index)
{
	assert(vector != NULL && data != NULL && index < vector->count);
	
	if (vector->count == vector->max_count)
		n_vector_resize(vector, vector->count * 2);
	memmove((t_byte*)vector->mem + vector->type_size * (index + 1),
		(t_byte*)vector->mem + vector->type_size * index, (vector->count - index + 1) * vector->type_size);
	memcpy((t_byte*)vector->mem + vector->type_size * index, data, vector->type_size);
	++(vector->count);
}

