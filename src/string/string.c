#include "nlibc/string.h"
#include <unistd.h>

String string_create(void)
{
	return (String){ .strvec = vector_create(sizeof(char), NULL) };
}

String string_create_cstr(char const* cstr)
{
	size_t len = strlen(cstr);
	String string = { .strvec = vector_create_count(sizeof(char), len, NULL) };
	vector_push_back_array(&(string.strvec), cstr, len);
	return (string);
}

String string_create_count(size_t count)
{
	return ((String){ vector_create_count(sizeof(char), count, NULL) });
}

void string_resize(String* string, size_t new_count)
{
	vector_resize(&(string->strvec), new_count);
}

void string_add_cstr(String* string, char const* cstr)
{
	size_t len = strlen(cstr);
	vector_push_back_array(&(string->strvec), cstr, len);
}

void string_add_char(String* string, char c)
{
	vector_push_back(&(string->strvec), &c);
}

char const* string_cstr(String* string)
{
	vector_push_back(&(string->strvec), &(char){'\0'});
	--(string->strvec.count);
	return (string->strvec.mem);
}

void string_free(String* string)
{
	vector_free(&(string->strvec));
}

ssize_t	string_write(String* string, int fd)
{
	return write(fd, string->strvec.mem, vector_size(&string->strvec));
}
