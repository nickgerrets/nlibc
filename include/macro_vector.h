#ifndef MACROVECTOR_H
# define MACROVECTOR_H

# define vector_t(T)				\
	struct s_vector_##T				\
	{								\
		T*		mem;				\
		size_t	count;				\
		size_t	capacity;			\
	}

# define vector_init(V) do {								\
		(V)->mem = malloc(sizeof(typeof(*(V)->mem)));		\
		(V)->count = 0;										\
		(V)->capacity = 1;									\
	} while (0)

# define vector_create(T) (struct s_vector_##T) {					\
		.mem = malloc(sizeof(T)),							\
		.count = 0,											\
		.capacity = 1										\
	}

# define vector_push_back(V, value) do {												\
		if ((V)->count >= (V)->capacity)												\
		{																				\
			(V)->capacity = (V)->capacity * 2;											\
			(V)->mem = realloc((V)->mem, sizeof(typeof(*(V)->mem)) * (V)->capacity);	\
		}																				\
		(V)->mem[(V)->count] = (value);													\
		(V)->count += 1;																\
	} while (0)



#endif // MACROVECTOR_H
