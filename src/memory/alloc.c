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
void	*n_alloc_array(size_t amount, size_t size)
{
	return (n_zalloc(amount * size));
}
