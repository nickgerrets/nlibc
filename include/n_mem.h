#ifndef N_MEM_H
# define N_MEM_H

# include <stddef.h>

//	memory.c
void	*n_memset(void *p, size_t size, char set);
void	*n_memcpy(void *dst, const void *src, size_t size);

#endif // N_MEM_H
