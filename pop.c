#include "monty.h"
/**
 *_pop - removes the top element of the stack
 *@stack: stack where top will be removed
 *@line: kine number of the command
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *top;

	top = *stack;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
