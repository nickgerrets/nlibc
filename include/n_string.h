/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   n_string.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 17:45:45 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/01 17:45:46 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_STRING_H
# define N_STRING_H

#include <stddef.h>
# include <stdlib.h>

typedef void (*t_str_f)(char *);

//	STRINGS
size_t	n_strlen(const char *str);
char	*n_strhaschar(const char *str, char c);
size_t	n_str_count_words(const char *str, const char *delims);
int		n_strcmp(const char *str1, const char *str2);
char	*n_strfind(const char *str, const char *sub);
int		n_strequals(const char *str1, const char *str2);

//	STRING ARRAYS
char	*n_str_first_word(const char *str, const char *delims);
char	**n_split(const char *str, const char *delims);
void	n_strarr_exec(char **arr, t_str_f func);
void	n_strarr_free(char **arr);
char	*n_strarr_find(char **arr, const char *str);

#endif // N_STRING_H
