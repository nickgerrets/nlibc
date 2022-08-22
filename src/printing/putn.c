#include "nlibc.h"

#include <unistd.h>

void	n_putint_fd(int n, int fd)
{
	if (n == -2147483648)
		n_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		write(fd, (char[]){'-'}, 1);
		n_putint_fd(-n, fd);
	}
	else if (n >= 10)
	{
		n_putint_fd(n / 10, fd);
		n_putint_fd(n % 10, fd);
	}
	else
		write(fd, (char[]){'0' + n}, 1);
}

void	n_putint(int n)
{
	n_putint_fd(n, STDOUT_FILENO);
}

void	n_putint_array(int *arr, size_t	count, char *sep)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		n_putint(arr[i]);
		i++;
		if (i < count)
			n_putstr(sep);
	}
}
