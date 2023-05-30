#include "n_string.h"
#include <unistd.h>

t_string n_string_create(void)
{
	return (t_string){ .strvec = n_vector_create(sizeof(char)) };
}

t_string n_string_create_cstr(char const* cstr)
{
	size_t len = strlen(cstr);
	t_string string = { .strvec = n_vector_create_count(sizeof(char), len) };
	n_vector_push_back_array(&(string.strvec), cstr, len);
	return (string);
}

t_string n_string_create_count(size_t count)
{
	return ((t_string){ n_vector_create_count(sizeof(char), count) });
}

void n_string_resize(t_string* string, size_t new_count)
{
	n_vector_resize(&(string->strvec), new_count);
}

void n_string_add_cstr(t_string* string, char const* cstr)
{
	size_t len = strlen(cstr);
	n_vector_push_back_array(&(string->strvec), cstr, len);
}

void n_string_add_char(t_string* string, char c)
{
	n_vector_push_back(&(string->strvec), &c);
}

char const* n_string_cstr(t_string* string)
{
	n_vector_push_back(&(string->strvec), &(char){'\0'});
	--(string->strvec.count);
	return (string->strvec.mem);
}

void n_string_free(t_string* string)
{
	n_vector_free(&(string->strvec));
}

ssize_t	n_string_write(t_string* string, int fd)
{
	return write(fd, string->strvec.mem, n_vector_size(&string->strvec));
}
