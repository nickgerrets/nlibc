#ifndef N_VECTOR_H
# define N_VECTOR_H

# include <stdlib.h>
# include <stddef.h>

# include "n_common.h"
# include "n_mem.h"

typedef struct s_vector
{
	void	*mem;
	size_t	max_count;
	size_t	curr_count;
	size_t	max_size;
	size_t	curr_size;
	size_t	element_size;
}	t_vector;

t_vector	n_vector_new(size_t _sizeof);
t_vector	n_vector_new_count(size_t _sizeof, size_t count);
void		n_vector_resize(t_vector *vector, size_t new_count);
void		n_vector_add_array(t_vector *vector, void const *data, size_t count);
void		n_vector_add(t_vector *vector, void const *data);
void		n_vector_free(t_vector *vector);
void		n_vector_iterate(t_vector *vector, t_data_f func);
void		n_vector_insert(t_vector *vector, void *data, size_t index);
void 		*n_vector_at(t_vector *vector, size_t index);
void 		*n_vector_last(t_vector *vector);

#endif // N_VECTOR_H
