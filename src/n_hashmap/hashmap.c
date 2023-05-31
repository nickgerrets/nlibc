#include "n_hashmap.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* Polynomial rolling hash function for C-strings */
uint64_t n_hash_cstr(char const *str)
{
	uint64_t hash = 0;
	uint64_t p = 31;
	uint64_t m = 1e9 + 7;
	uint64_t p_pow = 1;
	for (size_t i = 0; i < strlen(str); ++i)
	{
		hash = (hash * (str[i] - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return (hash);
}

hashmap_t n_hashmap_create(allocator_t const* allocator)
{
	if (allocator == NULL)
		allocator = n_allocator_default();

	hashmap_t map = {
		.allocator = *allocator,
		.buckets = allocator->alloc_f(HASHMAP_DEFAULT_BUCKET_AMOUNT * sizeof(hashmap_pair_t)),
		.buckets_amount = HASHMAP_DEFAULT_BUCKET_AMOUNT,
		.hashf = n_hash_cstr
	};

	if (map.buckets != NULL)
		memset(map.buckets, 0, HASHMAP_DEFAULT_BUCKET_AMOUNT * sizeof(hashmap_pair_t));
	return (map);
}

static hashmap_pair_t* _hm_find_bucket(hashmap_pair_t* bucket, uint64_t hash, char const* key)
{
	while (bucket)
	{
		if (bucket->hash == hash && strcmp(bucket->key, key) == 0)
			return (bucket);
		bucket = bucket->next;
	}
	return (NULL);
}

static hashmap_pair_t* _hm_last_bucket(hashmap_pair_t* bucket)
{
	while (bucket->next)
		bucket = bucket->next;
	return (bucket);
}

// TODO: use allocator for strdup'ing 'keys'?
hashmap_pair_t* n_hashmap_insert(hashmap_t* hashmap, char const* key, void* value)
{
	assert(hashmap != NULL && key != NULL);

	uint64_t hash = hashmap->hashf(key);
	size_t index = hash % hashmap->buckets_amount;

	hashmap_pair_t* bucket = hashmap->buckets + index;
	if (bucket->key == NULL)
	{
		*bucket = (hashmap_pair_t) {
			.hash = hash,
			.key = strdup(key),
			.value = value,
			.next = NULL
		};
		return (bucket);
	}

	bucket = _hm_last_bucket(bucket);
	bucket->next = hashmap->allocator.alloc_f(sizeof(hashmap_pair_t));
	if (bucket->next == NULL)
		return (NULL);
	*(bucket->next) = (hashmap_pair_t) {
		.hash = hash,
		.key = strdup(key),
		.value = value,
		.next = NULL
	};
	return (bucket->next);
}

void* n_hashmap_get(hashmap_t const* hashmap, char const* key)
{
	assert(hashmap != NULL && key != NULL);

	uint64_t hash = hashmap->hashf(key);
	size_t index = hash % hashmap->buckets_amount;

	hashmap_pair_t* bucket = hashmap->buckets + index;
	if (bucket->key == NULL)
		return (NULL);
	
	bucket = _hm_find_bucket(bucket, hash, key);
	if (bucket == NULL)
		return (NULL);
	return (bucket->value);
}

// TODO: using allocator for free-ing 'keys'?
void n_hashmap_free(hashmap_t* hashmap)
{
	assert(hashmap != NULL);

	for (size_t index = 0; index < hashmap->buckets_amount; ++index)
	{
		free(hashmap->buckets[index].key);
		hashmap_pair_t* list = hashmap->buckets[index].next;
		while (list)
		{
			hashmap_pair_t* next = list->next;
			free(list->key);
			hashmap->allocator.freef(list);
			list = next;
		}
	}
	hashmap->allocator.freef(hashmap->buckets);
	hashmap->buckets = NULL;
}
