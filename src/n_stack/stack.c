#include "n_stack.h"

t_stack	n_stack_new(size_t _sizeof)
{
	return ((t_stack){.data = n_vector_new(_sizeof)});
}

void	n_stack_push(t_stack *stack, void *data)
{
	n_vector_add(&(stack->data), data);
}

void	n_stack_pop(t_stack *stack)
{
	if (stack->data.curr_count > 0)
		stack->data.curr_count -= 1;
}

void	*n_stack_top(t_stack *stack)
{
	return (n_vector_last(&(stack->data)));
}
