#ifndef NLIBC_H
# define NLIBC_H

# include <stddef.h>
# include <unistd.h>

typedef void (*t_protect_f)(void);
# define N_PROTECT_F_DEFAULT n_error_and_exit

//	strlen.c
size_t	n_strlen(const char *str);

//	memory.c
void	n_memset(void *p, size_t size, char set);

//	alloc.c
void	*n_zalloc(size_t size);
void	*n_alloc_array(size_t amount, size_t size);

//	put.c
ssize_t	n_putstr_fd(const char *str, int fd);
ssize_t	n_putstr(const char *str);

//	putn.c
void	n_putint_fd(int n, int fd);
void	n_putint(int n);
void	n_putint_array(int *arr, size_t	count, char *sep);

#endif
