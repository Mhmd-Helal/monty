#include "monty.h"

/**
 * free_stack - frees a stack_t list.
 * @stack: a pointer to the top
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (!stack)
		return;
	tmp = stack;
	while (tmp)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
