#include "monty.h"
/**
 *_pint - prints the value at the top of the stack
 *@stack: name of the stack
 *@line: line number of the command
 *Return: void
 */
void _pint(stack_t **stack, unsigned int line)
{
	stack_t *current;

	current = *stack;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
