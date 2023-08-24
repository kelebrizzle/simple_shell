#include "shell.h"

/**
 * aux_help - Display help information for the 'help' builtin command.
 *
 * This function provides usage information and a brief summary of the 'help'
 * builtin command.
 *
 * Return: No return value.
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - Display help information for the 'alias' builtin command.
 *
 * This function provides usage information and a brief summary of the 'alias'
 * builtin command.
 *
 * Return: No return value.
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - Display help information for the 'cd' builtin command.
 *
 * This function provides usage information and a brief summary of the 'cd'
 * builtin command.
 *
 * Return: No return value.
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

