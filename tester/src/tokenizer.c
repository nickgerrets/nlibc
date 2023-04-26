#include "tester.h"

enum e_token_rule_type
{
	TOKEN_RULE_SPLIT,
	TOKEN_RULE_ENCAPSULATE
};

typedef struct s_token_rule t_token_rule;
struct s_token_rule
{
	enum e_token_rule_type	rule_type;
	int						token_id;
	union
	{
		struct s_token_rule_split
		{
			const char	*separators;
		}	split;
		struct s_token_rule_encapsulate
		{
			const char	*left;
			const char	*right;
		}	encapsulate;
	};
};

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


static void list_print(t_list *element)
{
	printf("(%s)->", (char *)element->content);
	if (!element->next)
		printf("NULL");
}

void tester_tokenizer(void)
{
	char * str = "hello there  =   how {1 {  2{3 }  }  {2} } you { 1okay? } {1{2{3{4}}}}  ";

	enum e_token_id
	{
		TOKEN_ASSIGN
	};

	t_token_rule rule_split = {.rule_type = TOKEN_RULE_SPLIT, .split.separators = "=", .token_id = TOKEN_ASSIGN};
	(void)rule_split;

	t_list *split = token_get_split(str, "=");

	// t_list *encap = token_get_encapsulate(str, "{", "}");

	IND; n_list_iterate(split, list_print); printf("\n");
	// IND; n_list_iterate(encap, list_print); printf("\n");

	char *p = str;
	char *tok = token_next_encapsulated(&p, "{", "}");

	IND; n_putstr_endl(tok);

	free(tok);

	n_list_free(split, free);
	// n_list_free(encap, free);

}
