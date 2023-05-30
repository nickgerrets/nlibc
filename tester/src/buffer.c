#include "tester.h"
#include "n_buffer.h"

#include <fcntl.h>

void test_buffer(void)
{
	LOG("BUFFER TESTS")

	buffer_t buffer = n_buffer_create(4096);
	TEST("n_buffer_create()", buffer.mem[0] == 0 && buffer.mem[buffer.max_size - 1] == 0);

	char const str[] = "Hello there!";
	n_buffer_add(&buffer, str, sizeof(str) - 1);
	TEST("n_buffer_add()", memcmp(buffer.mem, str, sizeof(str) - 1) == 0);

	int fd = open("../tester/testfile.txt", O_RDONLY);
	if (fd < 0)
		dprintf(STDERR_FILENO, "Couldn't open test file!\n");

	char const compare[] = "i_am_a_test_string";
	ssize_t read_size = n_buffer_read(&buffer, fd, sizeof(compare) - 1);
	TEST("n_buffer_read()",
		read_size == sizeof(compare) - 1
		&& memcmp(buffer.mem + sizeof(str) - 1, compare, sizeof(compare) - 1) == 0
	);
	close(fd);

	n_buffer_free(&buffer);
	TEST("n_buffer_free()", buffer.mem == NULL);
}
