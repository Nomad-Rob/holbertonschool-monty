#include "monty.h"
/**
 *_pall - prints all the values on the stack
 *@stack: linear data structure
 *@line: unused attribute
 *Return: void
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused)) line)
{
	int index = 0;
	stack_t *current;

	current = *stack;
	while (current)
	{
		if (current != NULL)
		printf("%d\n", current->n);
		index++;
		current = current->next;
	}
}
