#include "nlibc.h"
#include "tester.h"

# include <stdio.h>

void	custom_protect_func(void)
{
	n_putstr_fd("ERROR!", STDERR_FILENO);
}

static void put_digit_data_f(void *n)
{
	n_putint(*(int *)n);
	n_putchar(',');
}

int	main(void)
{
	tester_strings();

	// MEM TESTS
	NL; {
		int _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 9};
		int _array2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		n_putstr_endl("array before memmove:");
		n_putint_array(_array, sizeof(_array) / sizeof(int), ", ");

		n_putstr_endl("n_memmove() 9 elements 1 to the right");
		n_memmove(&_array[1], _array, 9 * sizeof(int));
		n_putstr_endl("array after memmove:");
		n_putint_array(_array, sizeof(_array) / sizeof(int), ", ");

		n_putstr_endl("array2 before n_memcpy:");
		n_putint_array(_array2, sizeof(_array2) / sizeof(int), ", ");
		n_putstr_endl("n_memcpy() 10 elements from array to array2");
		n_memcpy(_array2, _array, 10 * sizeof(int));
		n_putstr_endl("array2 after n_memcpy:");
		n_putint_array(_array2, sizeof(_array2) / sizeof(int), ", ");
	}

	// VECTOR TESTS
	NL; {
		int _array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

		t_vector vector = n_vector_new(sizeof(int));

		n_vector_add(&vector, &(int){4});
		n_vector_add(&vector, &(int){5});
		n_vector_add(&vector, &(int){6});

		n_vector_add_array(&vector, _array, sizeof(_array) / sizeof(int));

		n_vector_insert(&vector, &(int){666}, 2);

		n_putstr_endl("n_vector_iterate():");
		n_vector_iterate(&vector, put_digit_data_f); NL;
		printf("vector count / max_count: %lu/%lu\n", vector.curr_count, vector.max_count);

		n_vector_free(&vector);
	}

	NL; tester_lists();

	return (0);
}