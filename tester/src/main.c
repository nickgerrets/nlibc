#include "nlibc.h"
#include "tester.h"

# include <stdio.h>
# include <fcntl.h>

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
		IND; n_putint_array(_array, sizeof(_array) / sizeof(int), ", ");

		n_putstr_endl("n_memmove() 9 elements 1 to the right");
		n_memmove(&_array[1], _array, 9 * sizeof(int));
		n_putstr_endl("array after memmove:");
		IND; n_putint_array(_array, sizeof(_array) / sizeof(int), ", ");

		n_putstr_endl("array2 before n_memcpy:");
		IND; n_putint_array(_array2, sizeof(_array2) / sizeof(int), ", ");
		n_putstr_endl("n_memcpy() 10 elements from array to array2");
		n_memcpy(_array2, _array, 10 * sizeof(int));
		n_putstr_endl("array2 after n_memcpy:");
		IND; n_putint_array(_array2, sizeof(_array2) / sizeof(int), ", ");
	}

	NL; {
		printf("n_buffer_new() size 4096\n");
		t_buffer buffer = n_buffer_new(4096);

		printf("open() Makefile\n");
		int fd = open("Makefile", O_RDONLY);
		if (fd < 0)
			printf("can't open file\n");
		
		printf("n_buffer_read() 256 bytes from file\n");
		n_buffer_read(&buffer, fd, 256);

		printf("n_buffer_add() '[END]' to buffer\n");
		n_buffer_add(&buffer, "[END]", sizeof(char) * 5);

		printf("n_buffer_read() another 256 bytes from file\n");
		n_buffer_read(&buffer, fd, 256);

		printf("n_buffer_write() to STDOUT:\n");
		n_buffer_write(buffer, STDOUT_FILENO); NL;

		n_buffer_free(&buffer);

		close(fd);
	}

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

		n_putstr_endl("n_vector_iterate() with put digit:");
		IND; n_vector_iterate(&vector, put_digit_data_f); NL;
		printf("vector count / max_count: %lu/%lu\n", vector.curr_count, vector.max_count);

		printf("n_vector_free()\n");
		n_vector_free(&vector);
	}

	NL; tester_lists();
	NL; tester_tree();
	NL; tester_tokenizer();

	return (0);
}