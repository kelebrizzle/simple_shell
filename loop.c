#include "shell.h"

/**
 * without_comment - Deletes comments from the input string.
 *
 * @in: Input string.
 * Return: Input without comments.
 */
char *without_comment(char *in)
{
	int h, up_to;

	up_to = 0;
	for (h = 0; in[h]; h++)
	{
		if (in[h] == '#')
		{
			if (h == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[h - 1] == ' ' || in[h - 1] == '\t' || in[h - 1] == ';')
				up_to = h;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, h, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Main loop of the shell.
 *
 * @datash: Data relevant (av, input, args).
 * Return: No return value.
 */
void shell_loop(list_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "~$ ", 3);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->count += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

