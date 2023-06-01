/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 15:00:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2023/06/01 14:00:21 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "nlibc/buffer.h"

#include <string.h>
#include <unistd.h>
#include <assert.h>

Buffer buffer_create(size_t size)
{
	return (Buffer) {
		.mem = calloc(size, sizeof(byte_t)),
		.max_size = size,
		.curr_size = 0
	};
}

size_t buffer_add(Buffer* buffer, void const* data, size_t data_size)
{
	assert(buffer != NULL && buffer->mem != NULL);

	if (data_size > buffer->max_size - buffer->curr_size)
		data_size = buffer->max_size - buffer->curr_size;
	memcpy(buffer->mem + buffer->curr_size, data, data_size);
	buffer->curr_size += data_size;
	return (buffer->max_size - buffer->curr_size);
}

ssize_t buffer_write(Buffer const* buffer, int fd)
{
	assert(buffer != NULL && buffer->mem != NULL);

	return (write(fd, buffer->mem, buffer->curr_size));
}

ssize_t buffer_read(Buffer* buffer, int fd, size_t size)
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

void buffer_free(Buffer* buffer)
{
	assert(buffer != NULL);

	buffer->curr_size = 0;
	buffer->max_size = 0;
	free(buffer->mem);
	buffer->mem = NULL;
}
