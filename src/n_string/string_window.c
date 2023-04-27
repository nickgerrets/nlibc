#include "n_string.h"

t_string_window n_string_window_create(char const *start, size_t length)
{
	return ((t_string_window){.p = start, .length = length});
}

t_string_window	n_string_window_create_p(char const *start, char const *end)
{
	if (!start || !end || end < start)
		return ((t_string_window){.p = start, .length = 0});
	return ((t_string_window){.p = start, .length = (end - start) / sizeof(char)});
}

t_string_window	n_string_window_create_cstr(char const *cstr)
{
	return ((t_string_window){.p = cstr, .length = n_strlen_p(cstr)});
}

char	*n_string_window_dup(t_string_window strwin)
{
	char	*ret;

	ret = malloc((strwin.length + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	n_memcpy(ret, strwin.p, (strwin.length) * sizeof(char));
	ret[strwin.length] = '\0';
	return (ret);
}


ssize_t	n_string_window_write(t_string_window strwin, int fd)
{
	return (write(fd, strwin.p, sizeof(char) * strwin.length));
}
