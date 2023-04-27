#ifndef N_AST_H
# define N_AST_H

# include "n_list.h"

// SIMPLE EXPRESSION "4 + (3 - 1)" :
// '4' = literal
// '+' = binary expression
// '(3 - 1)' = expression

enum e_ast_rule_type
{
	AST_RULE_SPLIT,
	AST_RULE_ENCAP
};

// struct s_ast_rule
// {
// 	enum e_ast_rule_type	type;
// 	int						token_id;
// 	union
// 	{
// 		struct s_ast_rule_split
// 		{
// 			const char	*separators;
// 		}	split;
// 		struct s_ast_rule_encap
// 		{
// 			const char	*left;
// 			const char	*right;
// 		}	encapsulate;
// 	};
// };

// typedef struct s_ast_parser t_ast_parser;
// struct s_ast_parser
// {

// };

// enum e_token_type
// {
// 	TOKEN_PROGRAM,
// 	TOKEN_STATEMENT,
// 	TOKEN_LITERAL
// };

// typedef struct s_ast_node t_ast_node;
// struct s_ast_node
// {
// 	enum e_token_type token_type;

// 	union
// 	{
// 		struct s_token_literal // Literal is an end-point
// 		{
// 			char *literal;
// 		} literal;
// 		struct s_token_binary
// 		{
// 			t_ast_node *left;
// 			t_ast_node *right;
// 			char *op;
// 		} binary;
// 	};
// };

// TOKENIZE
t_list	*token_get_split(char const *str, char const *delimitors);
t_list	*token_get_encapsulate(char const *str, const char *left, const char *right);
char	*token_next_encapsulated(char **str, const char *left, const char *right);


#endif // N_AST_H
