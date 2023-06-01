#include "tester.h"
#include "nlibc/hashmap.h"

void test_hashmap(void)
{
	LOG("HASHMAP TESTS");

	Hashmap hm = hashmap_create(NULL);
	TEST("hashmap_create()",
		hm.buckets_amount == HASHMAP_DEFAULT_BUCKET_AMOUNT
		&& hm.buckets[0].key == NULL
		&& hm.buckets[hm.buckets_amount - 1].key == NULL
	);

	double x = 3.14;
	hashmap_insert(&hm, "pi", &x);
	size_t index = hash_cstr("pi") % hm.buckets_amount;
	TEST("hashmap_insert()", *(double*)hm.buckets[index].value == x);

	double* ptr = hashmap_get(&hm, "pi");
	TEST("hashmap_get()", *ptr == x);

	hashmap_free(&hm);
	TEST("hashmap_free()", hm.buckets == NULL);

}
