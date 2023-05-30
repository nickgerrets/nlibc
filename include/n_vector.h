#ifndef N_VECTOR_H
# define N_VECTOR_H

# include <stdlib.h>
# include <stddef.h>

# include "n_common.h"

# define N_VECTOR_GROWTH_FACTOR 2

typedef struct s_vector
{
	void	*mem;
	size_t	max_count;
	size_t	count;
	size_t	type_size;
}	t_vector;

typedef int (*t_compare_data_f)(void const * a, void const * b);

t_vector	n_vector_create(size_t _sizeof);
t_vector	n_vector_create_count(size_t _sizeof, size_t count);
void		n_vector_resize(t_vector *vector, size_t new_count);
void		n_vector_push_back_array(t_vector *vector, void const *data, size_t count);
void		n_vector_push_back(t_vector *vector, void const *data);
void		n_vector_free(t_vector *vector);
void		n_vector_iterate(t_vector *vector, t_data_f func);
void		n_vector_insert(t_vector *vector, void *data, size_t index);
void 		*n_vector_at(t_vector const * vector, size_t index);
void 		*n_vector_last(t_vector const * vector);
size_t		n_vector_search(t_vector const * vector, void const * search, t_compare_data_f compare_f);

size_t		n_vector_count(t_vector const * vector);
size_t		n_vector_max_count(t_vector const * vector);
size_t		n_vector_size(t_vector const * vector);
size_t		n_vector_max_size(t_vector const * vector);
size_t		n_vector_type_size(t_vector const * vector);
void *		n_vector_data(t_vector const * vector);

#endif // N_VECTOR_H
