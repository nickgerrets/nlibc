#ifndef MACROVECTOR_H
# define MACROVECTOR_H

# define vector_t(T)				\
	struct							\
	{								\
		T*		mem;				\
		size_t	count;				\
		size_t	max_count;			\
	}

# define vector_init(V) do {								\
		(V)->mem = malloc(sizeof(typeof(*(V).mem)));		\
		(V)->count = 0;										\
		(V)->max_count = 1;									\
	} while (0)

# define vector_push_back(V) do {															\
		if ((V).count >= (V).max_count)														\
		{																					\
			(V).mem = realloc((V).mem, sizeof(typeof(*(V).mem)) * (V).max_count * 2);		\
		}																					\
	} while(0)






#endif // MACROVECTOR_H
