#include "tester.h"
#include "n_hashmap.h"

void test_hashmap(void)
{
	LOG("HASHMAP TESTS");

	hashmap_t hm = n_hashmap_create();
	TEST("n_hashmap_create()",
		hm.buckets_amount == HASHMAP_DEFAULT_BUCKET_AMOUNT
		&& hm.buckets[0].key == NULL
		&& hm.buckets[hm.buckets_amount - 1].key == NULL
	);

	double x = 3.14;
	n_hashmap_insert(&hm, "pi", &x);
	size_t index = n_hash_cstr("pi") % hm.buckets_amount;
	TEST("n_hashmap_insert()", *(double*)hm.buckets[index].value == x);

	double* ptr = n_hashmap_get(&hm, "pi");
	TEST("n_hashmap_get()", *ptr == x);

	n_hashmap_free(&hm);
	TEST("n_hashmap_free()", hm.buckets == NULL);

}
