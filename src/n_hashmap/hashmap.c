#include "n_hashmap.h"
#include <stdint.h>
#include <string.h>

/* Polynomial rolling hash function for C-strings */
uint64_t n_hash_cstr(char const * str)
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

hashmap_t n_hashmap_create(void)
{
  hashmap_t map = {
    .buckets = calloc(HASHMAP_DEFAULT_BUCKET_AMOUNT, sizeof(hashmap_pair_t)),
    .buckets_amount = HASHMAP_DEFAULT_BUCKET_AMOUNT,
    .hashf = n_hash_cstr
  };
  return (map);
}

