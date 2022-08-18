#include "include/nlibc.h"

int	main(void)
{
	int	array[10];

	n_memset(array, 10 * sizeof(int), 0);

	return (0);
}