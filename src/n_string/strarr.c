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

static char	*_alloc_word(const char *str, const char *delims)
{
	size_t	i;
	size_t	len;
	char	*r;

	len = 0;
	while (str[len] && !n_strhaschar(delims, str[len]))
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = str[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	**n_split(const char *str, const char *delims)
{
	char	**arr;
	size_t	words;
	size_t	i;

	words = n_str_count_words(str, delims);
	arr = malloc(sizeof(char*) * (words + 1));
	if (!arr)
		return (NULL);
	if (words == 0)
	{
		*arr = NULL;
		return (arr);
	}
	i = 0;
	while (i < words)
	{
		str = n_str_first_word(str, delims);
		arr[i] = _alloc_word(str, delims);
		if (!arr[i])
		{
			arr[i] = NULL;
			n_strarr_free(arr);
			return (NULL);
		}
		while (*str && !n_strhaschar(delims, *str))
			str++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
