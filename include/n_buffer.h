#ifndef N_BUFFER_H
# define N_BUFFER_H

# include "n_common.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	t_byte	*mem;
	size_t	max_size;
	size_t	curr_size;
}	buffer_t;

// buffer.c
buffer_t	n_buffer_create(size_t size);
size_t		n_buffer_add(buffer_t* buffer, void const* data, size_t data_size);
ssize_t		n_buffer_write(buffer_t const* buffer, int fd);
ssize_t		n_buffer_read(buffer_t* buffer, int fd, size_t size);
void		n_buffer_free(buffer_t* buffer);

#endif // N_BUFFER_H
