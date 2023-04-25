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

// t_list *token_get_encapsulate(char const *str, const char *left, const char *right)
// {
// 	t_list *list;
// 	char *l, *r, *c;

// 	list = NULL;
// 	c = str;
// 	l = n_strfind(c, left);
// 	if (l)
// 	{
// 		r = n_strfind(l + 1, r);
// 		if (r)
// 		{
// 			// n_list_push_back(&list, n_list_new(NULL))
// 		}
// 	}
// 	return (list);
// }

static void list_print(t_list *element)
{
	printf("(%s)->", (char *)element->content);
	if (!element->next)
		printf("NULL");
}

void tester_tokenizer(void)
{
	char * str = "hello there  =   how are you";

	enum e_token_id
	{
		TOKEN_ASSIGN
	};

	t_token_rule rule_split = {.rule_type = TOKEN_RULE_SPLIT, .split.separators = "=", .token_id = TOKEN_ASSIGN};
	(void)rule_split;

	t_list *split = token_get_split(str, "=");

	IND; n_list_iterate(split, list_print); printf("\n");

	n_list_free(split, free);

}
