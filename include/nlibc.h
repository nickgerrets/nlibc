#ifndef NLIBC_H
# define NLIBC_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "n_string.h"
# include "n_alloc.h"
# include "n_protect.h"
# include "n_print.h"

typedef void (*t_protect_f)(void);
# define N_PROTECT_F_DEFAULT n_error_and_exit

//	memory.c
void	*n_memset(void *p, size_t size, char set);
void	*n_memcpy(void *dst, const void *src, size_t size);

//	protect.c
void		n_error_and_exit(void);
t_protect_f	n_protect_setf(t_protect_f func);
void		*n_protect(void *ptr);

//	alloc.c
void	*n_zalloc(size_t size);
void	*n_zalloc_array(size_t amount, size_t size);
void	*n_realloc(void *p, size_t old_size, size_t new_size);

#endif
