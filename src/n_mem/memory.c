/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 14:28:30 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 15:38:03 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_mem.h"
#include <stdlib.h>

void	*n_memset(void *p, size_t size, t_byte set)
{
	if (!p)
		return (NULL);
	while (size > 0)
	{
		*((t_byte *)p + size - 1) = set;
		size--;
	}
	return (p);
}

void	*n_memcpy(void *dst, const void *src, size_t size)
{
	void *ret;

	if (!(dst || src))
		return (NULL);
	ret = dst;
	while (size > 0)
	{
		*(t_byte *)dst++ = *(t_byte *)src++;
		--size;
	}
	return (ret);
}

void	*n_memmove(void *dst, const void *src, size_t size)
{
	if (!(dst || src))
		return (NULL);
	if (dst > src && dst < src + size)
	{
		while (size > 0)
		{
			*((t_byte *)dst + size - 1) = *((t_byte *)src + size - 1);
			--size;
		}
	}
	else
		n_memcpy(dst, src, size);
	return (dst);
}

void	*n_memdup(const void *src, size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	n_memcpy(mem, src, size);
	return (mem);
}

//	find byte in memory starting at p, ending at p + size (or NULL if not found)
void	*n_memfind(void *p, size_t size, t_byte find)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ( *((t_byte *)p + i) == find )
			return (p + i);
	}
	return (NULL);
}
