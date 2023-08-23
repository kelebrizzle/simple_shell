#include "shell.h"

/**
 * free_data - Frees memory allocated for the data structure.
 *
 * @datash: Data structure to be freed.
 * Return: No return value.
 */
void free_data(list_shell *datash)
{
	unsigned int n;

	for (n = 0; datash->_env[n]; n++)
	{
		free(datash->_env[n]);
	}

	free(datash->_env);
	free(datash->pid);
}

/**
 * set_data - Initializes the data structure with default values.
 *
 * @datash: Data structure to be initialized.
 * @av: Argument vector.
 * Return: No return value.
 */
void set_data(list_shell *datash, char **av)
{
	unsigned int n;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->count = 1;

	for (n = 0; env[n]; n++)
		;

	datash->_env = malloc(sizeof(char *) * (n + 1));

	for (n = 0; env[n]; n++)
	{
		datash->_env[n] = _strdup(env[n]);
	}

	datash->_env[n] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of the shell program.
 *
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	list_shell datash;
	(void)ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}

