#include "shell.h"

/**
 * check_environ - Checks if the typed variable is an environment variable.
 *
 * @h: Head of linked list.
 * @in: Input string.
 * @data: Data structure.
 * Return: No return.
 */
void check_environ(r_variable **h, char *in, list_shell *data)
{
	int row, chr, j, lval;
	char **_envriron;
	_envr = data->_env;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envriron[row][chr]; chr++)
		{
			if (_envriron[row][chr] == '=')
			{
				lval = _strlen(_envriron[row] + chr + 1);
				add_rvar_node(h, j, _envriron[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envriron[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - Check if the typed variable is $$ or $?
 *
 * @h: Head of the linked list.
 * @in: Input string.
 * @st: Last status of the Shell.
 * @data: Data structure.
 * Return: no return
 */
int check_vars(r_variable **h, char *in, char *st, list_shell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_environ(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - Replaces variables in the input string.
 *
 * @head: Head of the linked list.
 * @input: Input string.
 * @new_input: New input string (replaced).
 * @nlen: New length.
 * Return: Replaced string.
 */
char *replaced_input(r_variable **head, char *input, char *new_input, int nlen)
{
	r_variable *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - Calls functions to replace variables in the input string.
 *
 * @input: Input string.
 * @datash: Data structure.
 * Return: Replaced string
 */
char *rep_var(char *input, list_shell *datash)
{
	r_variable *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}

