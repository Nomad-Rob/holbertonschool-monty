#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @opcode: pointer to the string
 * @top_stack: linear data structure
 * @line: number of the line of the command
 * Return: void
 */
void _push(char *opcode, stack_t **top_stack, unsigned int line)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (_isnumber(opcode) == 1 && opcode != NULL)
	{
		new->n = atoi(opcode);
		new->next = *top_stack;
		new->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (*top_stack != NULL)
		(*top_stack)->prev = new;
	*top_stack = new;
}
