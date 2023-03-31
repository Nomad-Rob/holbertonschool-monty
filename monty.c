#include "monty.h"
/**
 *main - main function interpretes files
 *@argc: number of argv
 *@argv: arguments
 *Return: EXIT_SUCCESS or EXIT_FAILURE if the function fails
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fd;
	char *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg = argv[1];
	fd = fopen(arg, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	get_code(fd, &stack);
	_free(stack);
	fclose(fd);

	exit(EXIT_SUCCESS);
}

/**
 * get_code - gets the command
 * @file: file to read to gets the command
 * @stack: linear data structure
 *
 * Return: void
 */
void get_code(FILE *file, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t size = 0;
	int counter = 0;

	while (getline(&opcode, &size, file) != -1)
	{
		counter++;
		token = strtok(opcode, "\n\t\r ");
		if (token == NULL || *token == '#')
			continue;

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			_push(token, stack, counter);
		}
		else
			get_opc(token, stack, counter);
	}
	free(opcode);
}
