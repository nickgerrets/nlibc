#include "nlibc/vector.h"
#include <assert.h>
#include <string.h>

void vector_push_back(Vector *vector, void const *data)
{
	vector_push_back_array(vector, data, 1);
}

void vector_pop_back(Vector *vector)
{
	assert(vector != NULL);

	if (vector->count > 0)
		--(vector->count);
}

void vector_iterate(Vector* vector, data_func_t func)
{
	assert(vector != NULL && func != NULL);

	byte_t* data = vector->mem;
	size_t i = 0;
	while (i < vector->count)
	{
		func( (void *)(data + (i * vector->type_size)) );
		++i;
	}
}

void* vector_at(Vector const* vector, size_t index)
{
	assert(vector != NULL && index < vector->count);

	return ((byte_t*)vector->mem + (index * vector->type_size));
}

void* vector_last(Vector const* vector)
{
	assert(vector != NULL);
	
	if (vector->count == 0)
		return (NULL);
	return (vector_at(vector, vector->count - 1));
}

size_t vector_count(Vector const* vector)
{
	assert(vector != NULL);
	
	return (vector->count);
}

size_t vector_max_count(Vector const* vector)
{
	assert(vector != NULL);

	return (vector->max_count);
}

size_t vector_size(Vector const* vector)
{
	assert(vector != NULL);

	return (vector->count * vector->type_size);
}

size_t vector_max_size(Vector const* vector)
{
	assert(vector != NULL);

	return (vector->max_count * vector->type_size);
}

size_t vector_type_size(Vector const* vector)
{
	assert(vector != NULL);

	return (vector->type_size);
}

void* vector_data(Vector const* vector)
{
	assert(vector != NULL);

	return (vector->mem);
}

// Inserts element at index (if index is within scope)
void vector_insert(Vector* vector, void* data, size_t index)
{
	assert(vector != NULL && data != NULL && index < vector->count);
	
	if (vector->count == vector->max_count)
		vector_resize(vector, vector->count * 2);
	memmove((byte_t*)vector->mem + vector->type_size * (index + 1),
		(byte_t*)vector->mem + vector->type_size * index, (vector->count - index + 1) * vector->type_size);
	memcpy((byte_t*)vector->mem + vector->type_size * index, data, vector->type_size);
	++(vector->count);
}

