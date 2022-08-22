#include "nlibc.h"

#include <stdio.h>

int	main(void)
{
	int	array[10];

	printf("%zu\n", n_strlen("hello"));

	n_memset(array, 10 * sizeof(int), 0);
	n_putint_array(array, 10, ", ");
	return (0);
}