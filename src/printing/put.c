#include "nlibc.h"

ssize_t	n_putstr_fd(const char *str, int fd)
{
	return (write(fd, str, sizeof(char) * n_strlen(str)));
}

ssize_t	n_putstr(const char *str)
{
	return (n_putstr_fd(str, STDOUT_FILENO));
}
