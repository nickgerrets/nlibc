#ifndef N_BUFFER_H
# define N_BUFFER_H

# include "n_common.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_buffer
{
	void	*mem;
	size_t	max_size;
	size_t	curr_size;
}	t_buffer;

// buffer.c
t_buffer	n_buffer_new(size_t size);
size_t		n_buffer_add(t_buffer * buffer, void const * data, size_t data_size);
ssize_t		n_buffer_write(t_buffer const * buffer, int fd);
ssize_t		n_buffer_read(t_buffer * buffer, int fd, size_t size);
void		n_buffer_free(t_buffer * buffer);

#endif // N_BUFFER_H
