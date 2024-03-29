#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: the stack that point to the top
 * @line_number: the current line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}