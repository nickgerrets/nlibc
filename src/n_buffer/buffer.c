/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 15:00:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2023/05/30 17:32:05 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_buffer.h"

#include <string.h>
#include <unistd.h>
#include <assert.h>

buffer_t n_buffer_create(size_t size)
{
	return (buffer_t) {
		.mem = calloc(size, sizeof(t_byte)),
		.max_size = size,
		.curr_size = 0
	};
}

size_t n_buffer_add(buffer_t* buffer, void const* data, size_t data_size)
{
	assert(buffer != NULL && buffer->mem != NULL);

	if (data_size > buffer->max_size - buffer->curr_size)
		data_size = buffer->max_size - buffer->curr_size;
	memcpy(buffer->mem + buffer->curr_size, data, data_size);
	buffer->curr_size += data_size;
	return (buffer->max_size - buffer->curr_size);
}

ssize_t n_buffer_write(buffer_t const* buffer, int fd)
{
	assert(buffer != NULL && buffer->mem != NULL);

	return (write(fd, buffer->mem, buffer->curr_size));
}

ssize_t n_buffer_read(buffer_t* buffer, int fd, size_t size)
{
	assert(buffer != NULL && buffer->mem != NULL);

	if (buffer->curr_size + size > buffer->max_size)
		size = buffer->max_size - buffer->curr_size;
	ssize_t read_size = read(fd, buffer->mem + buffer->curr_size, size);
	if (read_size < 0)
		return (read_size);
	buffer->curr_size += (size_t)read_size;
	return (read_size);
}

void n_buffer_free(buffer_t* buffer)
{
	assert(buffer != NULL);

	buffer->curr_size = 0;
	buffer->max_size = 0;
	free(buffer->mem);
	buffer->mem = NULL;
}
