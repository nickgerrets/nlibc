#include "nlibc/protect.h"

#include <stdlib.h>
#include <stdio.h>

void	error_and_exit(void)
{
	//	TODO: put error
	perror(NULL);
	exit(EXIT_FAILURE);
}

protect_func_t	protect_setf(protect_func_t func)
{
	static protect_func_t	protf = PROTECT_F_DEFAULT;

	if (func != NULL)
		protf = func;
	return (protf);
}

void	*protect(void *ptr)
{
	if (!ptr)
		protect_setf(NULL)();
	return (ptr);
}
