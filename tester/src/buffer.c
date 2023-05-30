#include "tester.h"

void tester_buffer(void)
{

	NL; {
		printf("n_buffer_create() size 4096\n");
		t_buffer buffer = n_buffer_create(4096);

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
	
}
