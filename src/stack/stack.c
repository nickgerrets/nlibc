#include "nlibc/stack.h"

Stack	stack_create(size_t _sizeof)
{
	return ((Stack){.data = vector_create(_sizeof, NULL)});
}

void	stack_push(Stack *stack, void *data)
{
	vector_push_back(&(stack->data), data);
}

void	stack_pop(Stack *stack)
{
	if (stack->data.count > 0)
		stack->data.count -= 1;
}

void	*stack_top(Stack *stack)
{
	return (vector_last(&(stack->data)));
}

void	stack_free(Stack *stack)
{
	vector_free(&(stack->data));
}
