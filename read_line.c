#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * @i_eof: Pointer to store the return value of getline function.
 * Return: The input string entered by the user.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t buffsize = 0;

	*i_eof = getline(&input, &buffsize, stdin);

	return (input);
}

