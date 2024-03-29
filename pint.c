#include "monty.h"
/*
 * pint -  prints the value at the top of the stack
 *@stack: stack that point to the top
 *@line_number: num of line
*/

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}