#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include <stdint.h>

#include "allocator.h"

#define HASHMAP_DEFAULT_BUCKET_AMOUNT 61
/* this pair is currently just for cstr - void* pairing */
typedef struct s_hashmap_pair HashmapPair;
struct s_hashmap_pair
{
	char*			key;
	void*			value;
	uint64_t		hash;
	HashmapPair*	next;
};

typedef uint64_t (*hash_function_t)(char const *);

uint64_t	hash_cstr(char const *str);

typedef struct s_hashmap
{
	HashmapPair*	buckets;
	size_t			buckets_amount;
	hash_function_t	hashf;
	Allocator		allocator;
} Hashmap;


Hashmap			hashmap_create(Allocator const* allocator);
HashmapPair*	hashmap_insert(Hashmap* hashmap, char const* key, void* value);
void*			hashmap_get(Hashmap const* hashmap, char const* key);
void			hashmap_free(Hashmap* hashmap);


#endif // HASHMAP_H
