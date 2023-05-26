#include "n_string.h"
#include <unistd.h>

t_string	n_string_new(void)
{
	return ((t_string){n_vector_new(sizeof(char))});
}

t_string	n_string_new_cstr(char const *cstr)
{
	t_string	string;
	size_t 		len;

	len = n_strlen_p(cstr);
	string.strvec = n_vector_new_count(sizeof(char), len);
	n_vector_add_array(&(string.strvec), cstr, len);
	return (string);
}

t_string	n_string_new_count(size_t count)
{
	return ((t_string){n_vector_new_count(sizeof(char), count)});
}

void	n_string_resize(t_string *string, size_t new_count)
{
	n_vector_resize(&(string->strvec), new_count);
}

void	n_string_add_cstr(t_string *string, char const *cstr)
{
	size_t 		len;

	len = n_strlen_p(cstr);
	n_vector_add_array(&(string->strvec), cstr, len);
}

void	n_string_add_char(t_string *string, char c)
{
	n_vector_add(&(string->strvec), &c);
}

char const	*n_string_cstr(t_string *string)
{
	n_vector_add(&(string->strvec), &(char){'\0'});
	string->strvec.curr_count -= 1;
	string->strvec.curr_size -= string->strvec.type_size;
	return (string->strvec.mem);
}

void	n_string_free(t_string *string)
{
	n_vector_free(&(string->strvec));
}

ssize_t	n_string_write(t_string *string, int fd)
{
	return (write(fd, string->strvec.mem, string->strvec.curr_size));
}
