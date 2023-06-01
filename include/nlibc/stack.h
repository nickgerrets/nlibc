#ifndef STACK_H
# define STACK_H

# include "vector.h"

typedef struct s_stack Stack;
struct s_stack
{
	Vector data;
};

Stack	stack_create(size_t _sizeof);
void	stack_push(Stack *stack, void *data);
void	stack_pop(Stack *stack);
void	*stack_top(Stack *stack);
void	stack_free(Stack *stack);

#endif // STACK_H
