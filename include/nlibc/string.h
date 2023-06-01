#ifndef STRING_H
# define STRING_H

# include "vector.h"

# include <unistd.h>
# include <string.h>

typedef struct s_string String;
struct s_string
{
	Vector	strvec;
};

String	string_create(void);
String	string_create_cstr(char const *cstr);
String	string_create_count(size_t count);
void		string_resize(String *string, size_t new_count);
void		string_add_cstr(String *string, char const *cstr);
void		string_add_char(String *string, char c);
char const	*string_cstr(String *string);
ssize_t		string_write(String *string, int fd);
void		string_free(String *string);

typedef struct s_string_view
{
	char const*	p;
	size_t		length;
} StringView;

StringView	string_view_create(char const* start, size_t length);
StringView	string_view_create_p(char const* start, char const* end);
StringView	string_view_create_cstr(char const* cstr);

char	*string_view_dup(StringView const strwin);
ssize_t	string_view_write(StringView const strwin, int fd);
// void	string_view_move(StringView *strwin, int move);

#endif
