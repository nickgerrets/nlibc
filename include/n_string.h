#ifndef N_STRING_H
# define N_STRING_H

# include "n_vector.h"

# include <unistd.h>
# include <string.h>

typedef struct s_string t_string;
struct s_string
{
	t_vector	strvec;
};

t_string	n_string_new(void);
t_string	n_string_new_cstr(char const *cstr);
t_string	n_string_new_count(size_t count);
void		n_string_resize(t_string *string, size_t new_count);
void		n_string_add_cstr(t_string *string, char const *cstr);
void		n_string_add_char(t_string *string, char c);
char const	*n_string_cstr(t_string *string);
ssize_t		n_string_write(t_string *string, int fd);
void		n_string_free(t_string *string);

typedef struct s_string_window t_string_window;
struct s_string_window
{
	char const*	p;
	size_t		length;
};

t_string_window	n_string_window_create(char const* start, size_t length);
t_string_window	n_string_window_create_p(char const* start, char const* end);
t_string_window	n_string_window_create_cstr(char const* cstr);

char	*n_string_window_dup(t_string_window const strwin);
ssize_t	n_string_window_write(t_string_window const strwin, int fd);
// void	n_string_window_move(t_string_window *strwin, int move);

#endif
