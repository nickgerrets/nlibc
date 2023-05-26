#include "nlibc.h"
#include "tester.h"

#include <stdio.h>
#include <fcntl.h>

int vector_compare_int(void * a, void * b)
{
	return ( *(int *)a - *(int *)b );
}

static void put_digit_data_f(void *n)
{
	printf("%d, ", *(int *)n);
}

int	main(void)
{
//	tester_strings();

	// VECTOR TESTS
	NL; {
		int _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

		printf("n_vector_new() of int\n");
		t_vector vector = n_vector_new(sizeof(int));

		printf("n_vector_add() 4, 5 and 6\n");
		n_vector_add(&vector, &(int){4});
		n_vector_add(&vector, &(int){5});
		n_vector_add(&vector, &(int){6});

		printf("n_vector_add_array() 9 to 1\n");
		n_vector_add_array(&vector, _array, sizeof(_array) / sizeof(int));

		printf("n_vector_insert() 666 at position 2\n");
		n_vector_insert(&vector, &(int){666}, 2);

		printf("n_vector_iterate() with put digit:\n");
		IND; n_vector_iterate(&vector, put_digit_data_f); NL;
		printf("vector count / max_count: %lu/%lu\n", vector.curr_count, vector.max_count);


		printf("n_vector_search() for '5':\n");
		void * found = n_vector_search(&vector, &(int){5}, vector_compare_int);
		if (!found)
			printf("5 not found!\n");
		else
			printf("%d was found\n", *(int *)found);

		printf("n_vector_free()\n");
		n_vector_free(&vector);
	}

	// NL; tester_lists();
	// NL; tester_tree();
	// NL; tester_tokenizer();
	// NL; tester_stack();

	return (0);
}
