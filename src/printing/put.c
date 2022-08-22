#include "nlibc.h"

ssize_t	n_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(char)));
}

ssize_t	n_putchar(char c)
{
	return (n_putchar_fd(c, STDOUT_FILENO));
}

ssize_t	n_putstr_fd(const char *str, int fd)
{
	return (write(fd, str, sizeof(char) * n_strlen(str)));
}

ssize_t	n_putstr(const char *str)
{
	return (n_putstr_fd(str, STDOUT_FILENO));
}

ssize_t	n_putstr_endl(const char *str)
{
	ssize_t s;
	s = n_putstr(str);
	s += n_putchar('\n');
	return (s);
}
