#ifndef NLIBC_H
# define NLIBC_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef void (*t_protect_f)(void);
typedef void (*t_str_f)(char *);
# define N_PROTECT_F_DEFAULT n_error_and_exit

//	strlen.c
size_t	n_strlen(const char *str);
char	*n_strhaschar(const char *str, char c);
size_t	n_str_count_words(const char *str, const char *delims);
int		n_strcmp(const char *str1, const char *str2);
char	*n_strfind(const char *str, const char *sub);
int		n_strequals(const char *str1, const char *str2);

//	strarr.c
char	*n_str_first_word(const char *str, const char *delims);
char	**n_split(const char *str, const char *delims);
void	n_strarr_exec(char **arr, t_str_f func);
void	n_strarr_free(char **arr);
char	*n_strarr_find(char **arr, const char *str);

//	memory.c
void	n_memset(void *p, size_t size, char set);

//	protect.c
void		n_error_and_exit(void);
t_protect_f	n_protect_setf(t_protect_f func);
void		*n_protect(void *ptr);

//	alloc.c
void	*n_zalloc(size_t size);
void	*n_zalloc_array(size_t amount, size_t size);

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

#endif
