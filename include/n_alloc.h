/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   n_alloc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 14:42:02 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 15:06:19 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_ALLOC_H
# define N_ALLOC_H

# include "n_mem.h"

typedef struct	s_buffer
{
	void	*mem;
	size_t	max_size;
	size_t	curr_size;
}	t_buffer;

//	alloc.c
void	*n_zalloc(size_t size);
void	*n_zalloc_array(size_t amount, size_t size);
void	*n_realloc(void *p, size_t old_size, size_t new_size);
void	n_free_array(void* array, size_t count);

#endif // N_ALLOC_H
