#ifndef MY_SHELL_H
#define MY_SHELL_H

#define _GNU_SOURCE
#include <stdio.h>
#include "lists.h"

/**
 * struct param_s - Structure to hold essential shell variables
 * @argv: Command line arguments from main function
 * @buffer: Input buffer to store user input
 * @args: Array of arguments extracted from the input
 * @nextCommand: Pointer to the next command for processing
 * @argsCap: Capacity of the args array
 * @lineCount: Total lines of input processed
 * @tokCount: Number of tokens in the current input line
 * @status: Return status of the most recent command
 * @env_head: Singly linked list of environment variables
 * @alias_head: Singly linked list of aliases
 *
 * Description: This structure holds all the variables needed for various
 * parts of the shell's functionality, including command processing,
 * argument storage, environment variables, aliases, and more.
 */
typedef struct param_s
{
    char **argv;
    char *buffer;
    char **args;
    char *nextCommand;
    unsigned int argsCap;
    unsigned int lineCount;
    unsigned int tokCount;
    int status;
    list_t *env_head;
    list_t *alias_head;
} param_t;

/**
 * struct op - Represents a built-in shell function
 * @name: Name of the built-in function
 * @func: Pointer to the corresponding built-in function
 */
typedef struct op
{
    char *name;
    void (*func)(param_t *);
} op_t;

int process_string(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);

char *_strtok(char *str, char *delim, char **savePtr);

void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void _printenv(param_t *);

void sigint_handler(int);

char *_getenv(char *name, param_t *params);

void _setenv(param_t *params);

void _unsetenv(param_t *params);

char *get_file(param_t *params);

void (*get_builtin(param_t *params))(param_t *);

void _myExit(param_t *params);

void _cd(param_t *params);

void _alias(param_t *params);

void set_alias(char *name, param_t *params);

void make_alias(char *name, char *val, param_t *params);

void print_alias(char *name, param_t *params);

void print_all_aliases(param_t *params);

void print_list_env(list_t *);

void print_list_alias(list_t *);

void free_params(param_t *params);

void write_error(param_t *params, char *msg);

void _clear(param_t *params);

#endif

