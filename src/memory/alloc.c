#include "nlibc.h"
#include <stdlib.h>

//	Sets memory to 0
void	*n_zalloc(size_t size)
{
	void	*mem;
	
	mem = malloc(size);
	if (!mem)
		return (NULL);
	n_memset(mem, size, 0);
	return (mem);
}

//	Allocate amount * size
void	*n_zalloc_array(size_t amount, size_t size)
{
	return (n_zalloc(amount * size));
}

void	*n_realloc(void *p, size_t old_size, size_t new_size)
{
	void	*mem;

	mem = malloc(new_size);
	if (!mem || !p)
		return (mem);
	if (old_size > new_size)
		old_size = new_size;
	n_memcpy(mem, p, old_size);
	free(p);
	return (mem);
}
