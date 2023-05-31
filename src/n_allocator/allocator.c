#include "n_allocator.h"

allocator_t n_allocator_create(void* (*alloc_f)(size_t), void (*freef)(void*), void* (*realloc_f)(void*, size_t))
{
	alloc_f =	(alloc_f != NULL) ? alloc_f : ALLOCATOR_DEFAULT_ALLOC_F;
	freef =		(freef != NULL) ? freef : ALLOCATOR_DEFAULT_FREE_F;
	realloc_f =	(realloc_f != NULL) ? realloc_f : ALLOCATOR_DEFAULT_REALLOC_F;

	return (allocator_t) {
		.alloc_f = alloc_f,
		.freef = freef,
		.realloc_f = realloc_f
	};
}

allocator_t* n_allocator_default(void)
{
	static allocator_t default_allocator = {
		.alloc_f = ALLOCATOR_DEFAULT_ALLOC_F,
		.freef = ALLOCATOR_DEFAULT_FREE_F,
		.realloc_f = ALLOCATOR_DEFAULT_REALLOC_F
	};
	return (&default_allocator);
}
