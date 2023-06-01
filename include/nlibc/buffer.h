#ifndef BUFFER_H
# define BUFFER_H

# include "common.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	byte_t	*mem;
	size_t	max_size;
	size_t	curr_size;
}	Buffer;

// buffer.c
Buffer	buffer_create(size_t size);
size_t		buffer_add(Buffer* buffer, void const* data, size_t data_size);
ssize_t		buffer_write(Buffer const* buffer, int fd);
ssize_t		buffer_read(Buffer* buffer, int fd, size_t size);
void		buffer_free(Buffer* buffer);

#endif // BUFFER_H
