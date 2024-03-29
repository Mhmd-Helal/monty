#include "main.h"

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *str_element = strtok(NULL, "\n \t");
	int element;
    UNUSED (line_number);

	element = atoi(str_element);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
    new->n = element;
	new->next = NULL;
	if ((*stack) == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}

}