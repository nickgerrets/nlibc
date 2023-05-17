#ifndef N_STACK_H
# define N_STACK_H

# include "n_vector.h"

typedef struct s_stack t_stack;
struct s_stack
{
	t_vector data;
};

t_stack	n_stack_new(size_t _sizeof);
void	n_stack_push(t_stack *stack, void *data);
void	n_stack_pop(t_stack *stack);
void	*n_stack_top(t_stack *stack);
void	n_stack_free(t_stack *stack);

#endif // N_STACK_H
