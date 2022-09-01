/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strarr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 17:45:47 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/01 17:45:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "n_string.h"

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

char	*n_str_first_word(const char *str, const char *delims)
{
	while (n_strhaschar(delims, *str))
		str++;
	return ((char *)str);
}
