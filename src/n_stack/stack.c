#include "n_stack.h"

t_stack	n_stack_create(size_t _sizeof)
{
	return ((t_stack){.data = n_vector_create(_sizeof, NULL)});
}

void	n_stack_push(t_stack *stack, void *data)
{
	n_vector_push_back(&(stack->data), data);
}

void	n_stack_pop(t_stack *stack)
{
	if (stack->data.count > 0)
		stack->data.count -= 1;
}

void	*n_stack_top(t_stack *stack)
{
	return (n_vector_last(&(stack->data)));
}

void	n_stack_free(t_stack *stack)
{
	n_vector_free(&(stack->data));
}
