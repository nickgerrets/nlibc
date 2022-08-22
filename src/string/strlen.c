/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 18:22:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/08/22 18:43:29 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "nlibc.h"

size_t	n_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*n_strhaschar(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	n_str_count_words(const char *str, const char *delims)
{
	size_t	words;
	size_t	i;

	if (!str || n_strlen(str) == 0)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && n_strhaschar(delims, str[i]))
			i++;
		if (str[i])
			words++;
		while (str[i] && !n_strhaschar(delims, str[i]))
			i++;
	}
	return (words);
}

int	n_strcmp(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = n_strlen(str1);
	len2 = n_strlen(str2);
	if (len1 == 0 || len2 == 0)
		return (len2 - len1);
	i = 0;
	while (i < len1 && i < len2)
	{
		if ((unsigned char)str1[i] - (unsigned char)str2[i] != 0)
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	n_strequals(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = n_strlen(str1);
	len2 = n_strlen(str2);
	if (len1 != len2)
		return (0);
	i = 0;
	while (i < len1)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*n_strfind(const char *str, const char *sub)
{
	size_t	i;
	size_t	j;
	size_t	sublen;

	sublen = n_strlen(sub);
	if (!str || !sub || n_strlen(str) <=  sublen || sublen == 0)
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (sub[j] && str[i + j] && str[i + j] == sub[j])
			j++;
		if (j == n_strlen(sub))
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
