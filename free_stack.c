#include "main.h"

/**
 * free_stack - frees a stack_t list.
 * @stack: a pointer to the head
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
		stack = tmp;
		tmp = stack->next;
		free(stack);
	}
}