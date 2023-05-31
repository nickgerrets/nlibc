#ifndef N_HASHMAP_H
#define N_HASHMAP_H

#include <stddef.h>
#include <stdint.h>

#include "n_allocator.h"

#define HASHMAP_DEFAULT_BUCKET_AMOUNT 61
/* this pair is currently just for cstr - void* pairing */
typedef struct s_hashmap_pair hashmap_pair_t;
struct s_hashmap_pair
{
	char*			key;
	void*			value;
	uint64_t		hash;
	hashmap_pair_t*	next;
};

typedef uint64_t (*hash_function_t)(char const *);

uint64_t	n_hash_cstr(char const *str);

typedef struct s_hashmap
{
	hashmap_pair_t*	buckets;
	size_t			buckets_amount;
	hash_function_t	hashf;
	allocator_t		allocator;
} hashmap_t;


hashmap_t		n_hashmap_create(allocator_t const* allocator);
hashmap_pair_t*	n_hashmap_insert(hashmap_t* hashmap, char const* key, void* value);
void*			n_hashmap_get(hashmap_t const* hashmap, char const* key);
void			n_hashmap_free(hashmap_t* hashmap);


#endif // N_HASHMAP_H
