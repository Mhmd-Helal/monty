#ifndef _MAIN_H
#define _MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UNUSED(x) (void)(x)


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void pall(stack_t **stack, unsigned int line_number);
/*size_t getline(char **lineptr, size_t *n, FILE *stream);*/
#endif
