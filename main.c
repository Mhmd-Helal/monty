#include "monty.h"
#include <stdio.h>
/*
 * main - main function
 * @argc: num of arguments
 * @argv: array of arguments
 * Return: always return 0
*/


int main(int argc, char **argv)
{
	FILE *file_open;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL;
	size_t size = 0;
	int i = 0;
	char *opcode;
	instruction_t instrction;
	instruction_t arr[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open = fopen(argv[1], "r");
	if (file_open == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, file_open) != -1)
		{
			line_number++;
			opcode = strtok(line, "\n\t ");
			instrction.opcode = opcode;
			instrction.f = NULL;
			i = 0;
			while (arr[i].f != NULL)
			{
				if (strcmp(arr[i].opcode, opcode) == 0)
				{
					instrction.f = arr[i].f;
				}
				i++;
			}
			if (!(instrction.opcode) || instrction.opcode[0] == '#')
			{
				if (line)
					free(line);
				line = NULL;
				continue;
			}
			if (instrction.f)
				instrction.f(&stack, line_number);
			else
			{
				fprintf(stdout, "L%d: unknown instruction %s\n",
				line_number, instrction.opcode);
				if (line)
					free(line);
				if (stack)
					free_stack(stack);
				fclose(file_open);
				exit(EXIT_FAILURE);
			}
			

		}
		if (line)
			free(line);
		free_stack(stack);
		fclose(file_open);
		return (0);
}
