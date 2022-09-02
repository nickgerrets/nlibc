/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 15:00:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 15:17:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_alloc.h"
#include <unistd.h>

t_buffer	n_buffer_alloc(size_t size)
{
	t_buffer	buffer;

	buffer.mem = n_zalloc(size);
	buffer.max_size = size;
	buffer.curr_size = 0;
	return (buffer);
}

size_t	n_buffer_add(t_buffer buffer, void *data, size_t data_size)
{
	if (!buffer.mem)
		return (0);
	if (data_size > buffer.max_size - buffer.curr_size)
		data_size = buffer.max_size - buffer.curr_size;
	n_memcpy(buffer.mem + buffer.curr_size, data, data_size);
	buffer.curr_size += data_size;
	return (buffer.max_size - buffer.curr_size);
}

ssize_t	n_buffer_write(t_buffer buffer, int fd)
{
	return (write(fd, buffer.mem, buffer.curr_size));
}
