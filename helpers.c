#include "monty.h"
/**
 *get_opc - gets the function
 *@opcode: requested function
 *@cp_stack: linear data structure
 *@line: line number
 * Return: function pointer or EXIT_FAILURE if it fails
 */
void get_opc(char *opcode, stack_t **cp_stack, unsigned int line)
{
	int index = 0;

	instruction_t function[] = {
		{"pall", _pall},
		{"pint",  _pint},
		{"pop", _pop},
		{"swap", _swap},
		/*{"add", _add},*/
		/*{"nop", _nop},*/
		{NULL, NULL}
	};

	while (function[index].opcode)
	{
		if (strcmp(function[index].opcode, opcode) == 0)
		{
			function[index].f(cp_stack, line);
			break;
		}
		index++;
	}

	if (function[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 *_free - free stack memory
 *@head: pointer to the top of the stack
 *Return: void
 */
void _free(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 *_isnumber - checks for numbers
 *@opcode: string to check
 *Return: 1 if true, 0 otherwise
 */
int _isnumber(char *opcode)
{
	unsigned int index = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[index])
	{
		if (opcode[0] == '-')
		{
			index++;
			continue;
		}
		if (!isdigit(opcode[index]))
			return (0);
		index++;
	}
	return (1);
}
