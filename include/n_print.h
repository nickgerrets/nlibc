#ifndef N_PRINT_H
# define N_PRINT_H

#include <unistd.h>

#include "n_string.h"

//	put.c
ssize_t	n_putchar_fd(char c, int fd);
ssize_t	n_putchar(char c);
ssize_t	n_putstr_fd(const char *str, int fd);
ssize_t	n_putstr(const char *str);
ssize_t	n_putstr_endl(const char *str);

//	putn.c
void	n_putint_fd(int n, int fd);
void	n_putint(int n);
void	n_putint_array(int *arr, size_t	count, char *sep);

#endif // N_PRINT_H
