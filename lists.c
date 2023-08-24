#include "shell.h"

/**
 * add_sep_node_end - Adds a separator node at the end
 *                    of a sepp_lists.
 *
 * @head: Head of the linked list.
 * @sep: Separator found (; | &).
 * Return: Address of the head.
 */
sepp_lists *add_sep_node_end(sepp_lists **head, char sep)
{
	sepp_lists *new, *temp;

	new = malloc(sizeof(sepp_lists));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
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
 * free_sep_list - Frees a sepp_lists.
 *
 * @head: Head of the linked list.
 * Return: No return value.
 */
void free_sep_list(sepp_lists **head)
{
	sepp_lists *temp;
	sepp_lists *curr;

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

/**
 * add_line_node_end - Adds a command line node at the end
 *                     of a line_list.
 *
 * @head: Head of the linked list.
 * @line: Command line.
 * Return: Address of the head.
 */
line_l *add_line_node_end(line_l **head, char *line)
{
	line_l *new, *temp;

	new = malloc(sizeof(line_l));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * free_line_list - Frees a line_l.
 *
 * @head: Head of the linked list.
 * Return: No return value.
 */
void free_line_list(line_l **head)
{
	line_l *temp;
	line_l *curr;

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

