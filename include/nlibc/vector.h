#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <stddef.h>

# include "common.h"
# include "allocator.h"

# define VECTOR_GROWTH_FACTOR 2

typedef struct s_vector
{
	void		*mem;
	size_t		max_count;
	size_t		count;
	size_t		type_size;
	Allocator	allocator;
}	Vector;

typedef int (*compare_func_t)(void const * a, void const * b);

Vector	vector_create(size_t _sizeof, Allocator const* allocator);
Vector	vector_create_count(size_t _sizeof, size_t count, Allocator const* allocator);
void		vector_resize(Vector *vector, size_t new_count);
void		vector_push_back_array(Vector *vector, void const *data, size_t count);
void		vector_push_back(Vector *vector, void const *data);
void		vector_pop_back(Vector *vector);
void		vector_free(Vector *vector);
void		vector_iterate(Vector *vector, data_func_t func);
void		vector_insert(Vector *vector, void *data, size_t index);
void 		*vector_at(Vector const * vector, size_t index);
void 		*vector_last(Vector const * vector);
size_t		vector_search(Vector const * vector, void const * search, compare_func_t compare_f);

size_t		vector_count(Vector const * vector);
size_t		vector_max_count(Vector const * vector);
size_t		vector_size(Vector const * vector);
size_t		vector_max_size(Vector const * vector);
size_t		vector_type_size(Vector const * vector);
void *		vector_data(Vector const * vector);

#endif // VECTOR_H
