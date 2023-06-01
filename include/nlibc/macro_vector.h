#ifndef MACRO_VECTOR_H
# define MACRO_VECTOR_H

/*
*  Experimental vector implementation using macros.
*  (I believe I prefer the void* implemetation instead of macros)
*/

# define macro_vector_t(T)			\
	struct							\
	{								\
		T*		mem;				\
		size_t	count;				\
		size_t	capacity;			\
	}

# define macro_vector_init(V) do {							\
		(V)->mem = malloc(sizeof(typeof(*(V)->mem)));		\
		(V)->count = 0;										\
		(V)->capacity = 1;									\
	} while (0)

# define macro_vector_create(T) {	malloc(sizeof(T)), 0, 1 }

# define macro_vector_free(V) do {	\
		free((V)->mem);				\
		(V)->mem = NULL;			\
	} while (0)

# define macro_vector_push_back(V, value) do {											\
		if ((V)->count >= (V)->capacity)												\
		{																				\
			(V)->capacity = (V)->capacity * 2;											\
			(V)->mem = realloc((V)->mem, sizeof(typeof(*(V)->mem)) * (V)->capacity);	\
		}																				\
		(V)->mem[(V)->count] = (value);													\
		(V)->count += 1;																\
	} while (0)

# define macro_vector_pop_back(V) do {	\
		if ((V)->count > 0)				\
			(V)->count -= 1;			\
	} while (0)

# define macro_vector_at(V, index) ((V)->mem + index)

#endif // MACRO_VECTOR_H
