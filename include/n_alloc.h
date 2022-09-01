#ifndef N_ALLOC_H
# define N_ALLOC_H

# include "n_mem.h"

//	alloc.c
void	*n_zalloc(size_t size);
void	*n_zalloc_array(size_t amount, size_t size);
void	*n_realloc(void *p, size_t old_size, size_t new_size);

#endif // N_ALLOC_H
