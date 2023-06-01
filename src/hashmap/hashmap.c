#include "nlibc/hashmap.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* Polynomial rolling hash function for C-strings */
uint64_t hash_cstr(char const *str)
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

Hashmap hashmap_create(Allocator const* allocator)
{
	if (allocator == NULL)
		allocator = allocator_default();

	Hashmap map = {
		.allocator = *allocator,
		.buckets = allocator->alloc_f(HASHMAP_DEFAULT_BUCKET_AMOUNT * sizeof(HashmapPair)),
		.buckets_amount = HASHMAP_DEFAULT_BUCKET_AMOUNT,
		.hashf = hash_cstr
	};

	if (map.buckets != NULL)
		memset(map.buckets, 0, HASHMAP_DEFAULT_BUCKET_AMOUNT * sizeof(HashmapPair));
	return (map);
}

static HashmapPair* _hm_find_bucket(HashmapPair* bucket, uint64_t hash, char const* key)
{
	while (bucket)
	{
		if (bucket->hash == hash && strcmp(bucket->key, key) == 0)
			return (bucket);
		bucket = bucket->next;
	}
	return (NULL);
}

static HashmapPair* _hm_last_bucket(HashmapPair* bucket)
{
	while (bucket->next)
		bucket = bucket->next;
	return (bucket);
}

// TODO: use allocator for strdup'ing 'keys'?
HashmapPair* hashmap_insert(Hashmap* hashmap, char const* key, void* value)
{
	assert(hashmap != NULL && key != NULL);

	uint64_t hash = hashmap->hashf(key);
	size_t index = hash % hashmap->buckets_amount;

	HashmapPair* bucket = hashmap->buckets + index;
	if (bucket->key == NULL)
	{
		*bucket = (HashmapPair) {
			.hash = hash,
			.key = strdup(key),
			.value = value,
			.next = NULL
		};
		return (bucket);
	}

	bucket = _hm_last_bucket(bucket);
	bucket->next = hashmap->allocator.alloc_f(sizeof(HashmapPair));
	if (bucket->next == NULL)
		return (NULL);
	*(bucket->next) = (HashmapPair) {
		.hash = hash,
		.key = strdup(key),
		.value = value,
		.next = NULL
	};
	return (bucket->next);
}

void* hashmap_get(Hashmap const* hashmap, char const* key)
{
	assert(hashmap != NULL && key != NULL);

	uint64_t hash = hashmap->hashf(key);
	size_t index = hash % hashmap->buckets_amount;

	HashmapPair* bucket = hashmap->buckets + index;
	if (bucket->key == NULL)
		return (NULL);
	
	bucket = _hm_find_bucket(bucket, hash, key);
	if (bucket == NULL)
		return (NULL);
	return (bucket->value);
}

// TODO: using allocator for free-ing 'keys'?
void hashmap_free(Hashmap* hashmap)
{
	assert(hashmap != NULL);

	for (size_t index = 0; index < hashmap->buckets_amount; ++index)
	{
		free(hashmap->buckets[index].key);
		HashmapPair* list = hashmap->buckets[index].next;
		while (list)
		{
			HashmapPair* next = list->next;
			free(list->key);
			hashmap->allocator.freef(list);
			list = next;
		}
	}
	hashmap->allocator.freef(hashmap->buckets);
	hashmap->buckets = NULL;
}
