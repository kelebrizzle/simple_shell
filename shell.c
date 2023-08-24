#include "shell.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(list_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_env[i]; i++)
	{
		free(datash->_env[i]);
	}

	free(datash->_env);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(list_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->count = 1;

	for (i = 0; env[i]; i++)
		;

	datash->_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; env[i]; i++)
	{
		datash->_env[i] = _strdup(env[i]);
	}

	datash->_env[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	list_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
