#include "nlibc.h"

size_t	n_strlen(const char *str)
{
	size_t	len;

	while (*(str + len))
		len++;
	return (len);
}
