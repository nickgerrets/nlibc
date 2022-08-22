#include "nlibc.h"

void	n_memset(void *p, size_t size, char set)
{
	while (size > 0)
	{
		*((char *)p + size - 1) = set;
		size--;
	}
}
