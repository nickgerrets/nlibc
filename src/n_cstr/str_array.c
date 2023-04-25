/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_array.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 17:45:47 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 14:40:49 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_cstr.h"

void	n_strarr_exec(char **arr, t_str_f func)
{
	while (*arr)
	{
		func(*arr);
		arr++;
	}
}

void	n_strarr_free(char **arr)
{
	n_strarr_exec(arr, (t_str_f)free);
	free(arr);
}

char	*n_strarr_find(char **arr, const char *str)
{
	while (*arr)
	{
		if (n_strequals(*arr, str))
			return (*arr);
		arr++;
	}
	return (NULL);
}

size_t	n_strarr_size(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
