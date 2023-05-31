#include "tester.h"

#include <stdbool.h>

enum e_token_type
{
	TOKEN_UNKNOWN,
	TOKEN_LITERAL,				// 8909 | abc
	TOKEN_OPERATOR,				// + - / *
	TOKEN_END_STATEMENT,		// ;
	TOKEN_LEFT_PARENTHESES,		// (
	TOKEN_RIGHT_PARENTHESES,	// )
	TOKEN_DQUOTE,				// "
	TOKEN_SQUOTE				// '
};

typedef struct s_token t_token;
struct s_token
{
	enum e_token_type type;
	t_string_window window;
};

static bool is_alnum(char c)
{
	return (
		(c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c == '_'));
}

static bool is_operator(char c)
{
	return (
		(c == '+') ||
		(c == '-') ||
		(c == '*') ||
		(c == '/'));
}

enum e_token_type get_token_type(char c)
{
	if (is_alnum(c))
		return (TOKEN_LITERAL);
	if (is_operator(c))
		return (TOKEN_OPERATOR);
	switch (c)
	{
		case ';': return (TOKEN_END_STATEMENT);
		case '(': return (TOKEN_LEFT_PARENTHESES);
		case ')': return (TOKEN_RIGHT_PARENTHESES);
		case '\"': return (TOKEN_DQUOTE);
		case '\'': return (TOKEN_SQUOTE);
		default: break ;
	}
	return (TOKEN_UNKNOWN);
}

t_token parse_token(char const ** str, enum e_token_type type)
{
	t_token token;
	char const * endp;

	token.type = type;
	switch (type)
	{
		case TOKEN_OPERATOR:
		case TOKEN_END_STATEMENT:
		case TOKEN_LEFT_PARENTHESES:
		case TOKEN_RIGHT_PARENTHESES:
		case TOKEN_DQUOTE:
		case TOKEN_SQUOTE:
			token.window = n_string_window_create(*str, 1);
			*str += 1;
			break ;
		case TOKEN_LITERAL:
			endp = *str;
			while (*endp && is_alnum(*endp))
				++endp;
			token.window = n_string_window_create_p(*str, endp);
			*str = endp;
			break ;
		default: break ;
	}
	return (token);
}

typedef struct s_ast_node t_ast_node;
struct s_ast_node
{
	enum e_token_type token_type;

	union
	{
		struct s_token_literal // Literal is an end-point
		{
			char *literal;
		} literal;
		struct s_token_binary
		{
			t_ast_node *left;
			t_ast_node *right;
			char *op;
		} binary;
	};
};

static char const *token_type_to_string(enum e_token_type type)
{
	switch (type)
	{
		case TOKEN_OPERATOR: 			return ("OPERATOR");
		case TOKEN_END_STATEMENT: 		return ("END_STATEMENT");
		case TOKEN_LEFT_PARENTHESES: 	return ("LEFT_PARENTHESES");
		case TOKEN_RIGHT_PARENTHESES: 	return ("RIGHT_PARENTHESES");
		case TOKEN_DQUOTE: 				return ("DQUOTE");
		case TOKEN_SQUOTE: 				return ("SQUOTE");
		case TOKEN_LITERAL: 			return ("LITERAL");
		default: break ;
	}
	return ("UNKNOWN");
}

static void token_print(void *data)
{
	t_token *token = (t_token *)data;
	if (!token)
	{
		printf("NULL");
		return ;
	}
	char *str = n_string_window_dup(token->window);
	printf("\t%s(\"%s\")\n",
		token_type_to_string(token->type),
		str);
	free(str);
}

// "4 + 5;"
// LITERAL OPERATOR LITERAL ->
// BINARY_EXPRESSION ->
// BINARY_EXPRESSION ; ->
// STATEMENT

// "4 + (1 + 1);"
// LITERAL OPERATOR ( LITERAL OPERATOR LITERAL ->
// LITERAL OPERATOR ( BINARY_EXPRESSION ->
// LITERAL OPERATOR ( BINARY_EXPRESSION ) ->
// LITERAL OPERATOR EXPRESSION ->
// BINARY_EXPRESSION ->
// BINARY_EXPRESSION ; ->
// STATEMENT

void debug_print_vector(t_vector * vector)
{
	printf("VECTOR_DEBUG_PRINT:\n\tmem: %p\n\tcount: %lu\n\tmax_count: %lu\n",
		vector->mem,
		vector->count,
		vector->max_count
		);
}

void test_tokenizer(void)
{
	t_stack token_stack = n_stack_create(sizeof(t_token));
	char const * str = "4642 + 77 + (a + b);";

	char const * p = str;
	while (*p)
	{
		while ( strchr("\n\t ", *p) != NULL )
			++p;
		t_token token = parse_token(&p, get_token_type(*p));
		n_stack_push(&token_stack, &token);
		// Check stack for consequetive tokens that are a rule
	}
	n_vector_iterate(&(token_stack.data), token_print);

	debug_print_vector(&(token_stack.data));

	t_token * top = n_stack_top(&token_stack);
	printf("STACK TOP: %s\n", token_type_to_string(top->type));

	n_stack_free(&token_stack);


	// IND; n_list_iterate(tokens, token_list_print);

	// n_list_free(tokens, free);

	// t_list *split = token_get_split(str, ";");

	// // t_list *encap = token_get_encapsulate(str, "{", "}");

	// IND; n_list_iterate(split, list_print); printf("\n");
	// // IND; n_list_iterate(encap, list_print); printf("\n");

	// char *p = str;
	// char *tok = token_next_encapsulated(&p, "{", "}");

	// if (tok) { IND; n_putstr_endl(tok); }

	// free(tok);

	// n_list_free(split, free);
	// n_list_free(encap, free);

}
