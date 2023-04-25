/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 15:00:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 15:50:56 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_alloc.h"
#include <unistd.h>

t_buffer	n_buffer_new(size_t size)
{
	t_buffer	buffer;

	buffer.mem = n_zalloc(size);
	buffer.max_size = size;
	buffer.curr_size = 0;
	return (buffer);
}

size_t	n_buffer_add(t_buffer *buffer, const void *data, size_t data_size)
{
	if (!buffer->mem)
		return (0);
	if (data_size > buffer->max_size - buffer->curr_size)
		data_size = buffer->max_size - buffer->curr_size;
	n_memcpy(buffer->mem + buffer->curr_size, data, data_size);
	buffer->curr_size += data_size;
	return (buffer->max_size - buffer->curr_size);
}

ssize_t	n_buffer_write(t_buffer buffer, int fd)
{
	return (write(fd, buffer.mem, buffer.curr_size));
}

ssize_t	n_buffer_read(t_buffer *buffer, int fd, size_t size)
{
	ssize_t read_size;

	if (buffer->curr_size + size > buffer->max_size)
		size = buffer->max_size - buffer->curr_size;
	read_size = read(fd, (t_byte *)buffer->mem + buffer->curr_size, size);
	if (read_size < 0)
		return (read_size);
	buffer->curr_size += (size_t)read_size;
	return (read_size);

}

void n_buffer_free(t_buffer *buffer)
{
	buffer->curr_size = 0;
	buffer->max_size = 0;
	free(buffer->mem);
	buffer->mem = NULL;
}
