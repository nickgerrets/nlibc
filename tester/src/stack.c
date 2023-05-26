#include "n_stack.h"
#include "tester.h"

void print_stack(t_stack *stack)
{
	printf("STACK:\n\tcurr_count: %lu\n\tcurr_size: %lu\n\ttype_size: %lu\n\tmax_count: %lu\n\tmax_size: %lu\n",
		stack->data.curr_count,
		stack->data.curr_size,
		stack->data.type_size,
		stack->data.max_count,
		stack->data.max_size
		);
}


void tester_stack(void)
{
	struct element {
		int n;
		char * str;
	};
	
	NL; {
		n_putstr_endl("Creating a stack with n_stack_new():");
		t_stack stack = n_stack_new(sizeof(struct element));

		struct element e = {
			.n = 1,
			.str = "ELEMENT!"
		};

		n_putstr_endl("Pushing element to stack with n_stack_push():");
		n_stack_push(&stack, &e);
		
		n_putstr_endl("Pushing another element and getting n_stack_top():");
		struct element e2 = {
			.n = 2,
			.str = "Hello there"
		};
		n_stack_push(&stack, &e2);
		
		print_stack(&stack); 

		struct element * ptr = stack.data.mem;
		printf("\tptr = %p\n\tn = %d\n\tstr = %s\n", ptr, ptr->n, ptr->str);
		++ptr;
		printf("\tptr = %p\n\tn = %d\n\tstr = %s\n", ptr, ptr->n, ptr->str);
		
		n_putstr_endl("Getting top of stack with n_stack_top():");
		struct element * top = n_stack_top(&stack);
		printf("\ttop(stack) = %p\n", top);
		top = n_vector_last(&stack.data);
		printf("\ttop(vector) = %p\n", top);
		
				// printf("\tn = %d\n\tstr = %s\n", top->n, top->str);
	
		//top = n_stack_top(&stack);
		// printf("\tn = %d\n\tstr = %s\n", top->n, top->str);
		
		n_putstr_endl("Freeing stack with n_stack_free():");
		n_stack_free(&stack);
		
	}
	
}
