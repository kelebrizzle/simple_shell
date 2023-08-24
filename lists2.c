#include "shell.h"

/**
 * add_rvar_node - Adds a variable node at the end
 *                 of an r_variable list.
 *
 * @head: Head of the linked list.
 * @lvar: Length of the variable.
 * @val: Value of the variable.
 * @lval: Length of the value.
 * Return: Address of the head.
 */
r_variable *add_rvar_node(r_variable **head, int lvar, char *val, int lval)
{
	r_variable *new, *temp;

	new = malloc(sizeof(r_variable));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - Frees an r_variable list.
 *
 * @head: Head of the linked list.
 * Return: No return value.
 */
void free_rvar_list(r_variable **head)
{
	r_variable *temp;
	r_variable *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

