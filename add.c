#include "monty.h"
/**
 * _add - adds the top two elements of the stack
 * @stack: stack
 * @line: line number of the command
 * Return: void
 */
void _add(stack_t **stack, unsigned int line)
{
	int first, second, res;
	stack_t *top;

	top = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	first = top->n;
	second = top->next->n;
	res = first + second;
	_pop(stack, line);
	(*stack)->n = res;
}
