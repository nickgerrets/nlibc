#include "n_mem.h"

void	*n_memset(void *p, size_t size, char set)
{
	while (size > 0)
	{
		*((char *)p + size - 1) = (unsigned char)set;
		size--;
	}
	return (p);
}

void	*n_memcpy(void *dst, const void *src, size_t size)
{
	while (size > 0)
	{
		*((char *)dst + size - 1) = *((char *)src + size - 1);
		size--;
	}
	return (dst);
}
