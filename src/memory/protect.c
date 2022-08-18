#include "nlibc.h"

#include <stdlib.h>

typedef void (*t_protect_f)(void);

#define N_PROTECT_F_DEFAULT n_error_and_exit

void	n_error_and_exit(void)
{
	//	TODO: put error
	exit(EXIT_FAILURE);
}

t_protect_f	n_protect_setf(t_protect_f func)
{
	static t_protect_f	protf = N_PROTECT_F_DEFAULT;

	if (func != NULL)
		protf = func;
	return (protf);
}

void	*n_protect(void *ptr)
{
	if (!ptr)
		n_protect_setf(NULL)();
	return (ptr);
}
