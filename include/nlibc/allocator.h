#ifndef ALLOCATOR_H
# define ALLOCATOR_H

# include <stdlib.h>

# define ALLOCATOR_DEFAULT_ALLOC_F malloc
# define ALLOCATOR_DEFAULT_FREE_F free
# define ALLOCATOR_DEFAULT_REALLOC_F realloc

/* in practice just a struct that holds three function pointers */
typedef struct s_allocator
{
	void* (*alloc_f)(size_t);
	void (*freef)(void*);
	void* (*realloc_f)(void*, size_t);
} Allocator;

Allocator allocator_create(void* (*alloc_f)(size_t), void (*freef)(void*), void* (*realloc_f)(void*, size_t));
Allocator* allocator_default(void);

#endif // ALLOCATOR_H
