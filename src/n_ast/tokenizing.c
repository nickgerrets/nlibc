#include "n_ast.h"

#include "n_list.h"
#include "n_string.h"

t_list *token_get_split(char const *str, char const *delimitors)
{
	t_list	*list;
	char	**split;
	size_t	i;

	list = NULL;
	split = n_split(str, delimitors);
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		n_list_push_back(&list, n_list_new(split[i]));
		++i;
	}
	free(split);
	return (list);
}

t_list *token_get_encapsulate(char const *str, const char *left, const char *right)
{
	t_list *list;
	char *l, *r;

	list = NULL;
	l = n_strfind(str, left);
	while (l)
	{
		r = l;
		r = n_strfind(r + 1, right);
		char *f = l;
		while (f)
		{
			f = n_strfind(f + 1, left);
			if (f && f < r)
				r = n_strfind(r + 1, right);
		}
		if (!r)
			break ;
		t_string_window strwin = n_string_window_create_p(l + 1, r);
		if (strwin.length > 0)
			n_list_push_back(&list, n_list_new(n_string_window_dup(strwin)));
		l = n_strfind(r + 1, left);
	}

	t_list *e;
	e = list;
	while (e)
	{
		t_list *new = token_get_encapsulate(e->content, left, right);
		if (new)
			n_list_push_back(&list, new);
		e = e->next;
	}

	return (list);
}

char *token_next_encapsulated(char **str, const char *left, const char *right)
{
	char	*l;
	char	*r;

	l = n_strfind(*str, left);
	if (!l)
		return (NULL);
	r = l;
	r = n_strfind(r + 1, right);
	char *f = l;
	while (f)
	{
		f = n_strfind(f + 1, left);
		if (f && f < r)
			r = n_strfind(r + 1, right);
	}
	if (!r)
		return (NULL);
	*str = r + 1;
	t_string_window strwin = n_string_window_create_p(l + 1, r);
	if (strwin.length > 0)
		return (n_string_window_dup(strwin));
	return (NULL);
}
