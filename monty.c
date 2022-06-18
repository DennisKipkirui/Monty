#include "monty.h"
/**
 * readfile - reads every line of a file
 * @filename: path of the file(string)
 *
 * Return: void
 */
void readfile(char *filename)
{
	stack_t *stack = NULL;
	int line_number = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		line_number++;
		tokens = parse_line(buffer);
		if (tokens == NULL)
			continue;
		else
			get_op_func(tokens, line_number)(&stack, line_number);
	}
	fclose(file);
	free(buffer);
	free_list(&stack);
}

/**
 * main - entry point - handle user input from the command line
 * @argc: argument count
 * @argv: arguments (strings)
 * Return: 0 for success, EXIT_FAILURE on errors
 */
int main(int argc, char *argv[])
{
	char *filename;

	filename = argv[1];
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(filename);
	return (0);
}
