#include "nlibc/string.h"

StringView string_view_create(char const* start, size_t length)
{
	return (StringView) {
		.p = start,
		.length = length
	};
}

StringView string_view_create_p(char const* start, char const* end)
{
	if (!start || !end || end < start)
		return (StringView) {
			.p = start,
			.length = 0
		};
	return (StringView) {
		.p = start,
		.length = (end - start) / sizeof(char)
	};
}

StringView string_view_create_cstr(char const* cstr)
{
	return (StringView) {
		.p = cstr,
		.length = strlen(cstr)
	};
}

char* string_view_dup(StringView const strwin)
{
	char* ret = malloc((strwin.length + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	memcpy(ret, strwin.p, strwin.length * sizeof(char));
	ret[strwin.length] = '\0';
	return (ret);
}


ssize_t string_view_write(StringView const strwin, int fd)
{
	return (write(fd, strwin.p, sizeof(char) * strwin.length));
}
