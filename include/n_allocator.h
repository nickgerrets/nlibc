#ifndef N_ALLOCATOR_H
# define N_ALLOCATOR_H

# include <stdlib.h>

# define ALLOCATOR_DEFAULT_ALLOC_F malloc
# define ALLOCATOR_DEFAULT_FREE_F free
# define ALLOCATOR_DEFAULT_REALLOC_F realloc

/* in practice just a struct that holds two function pointers */
typedef struct s_allocator
{
	void* (*alloc_f)(size_t);
	void (*freef)(void*);
	void* (*realloc_f)(void*, size_t);
} allocator_t;

allocator_t n_allocator_create(void* (*alloc_f)(size_t), void (*freef)(void*), void* (*realloc_f)(void*, size_t));
allocator_t* n_allocator_default(void);

#endif // N_ALLOCATOR_H
