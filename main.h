#ifndef _MAIN_H_
#define _MAIN_H_
#define NULL_POINTER -1
#define ERROR_SPECIFIER -2

/**
 * get_char - insert a character into a memory block allocated using malloc
 * The allocated memory has two bytes: the character, and the
 * terminating null byte.
 *
 * @c: character
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_char(char c);

/**
 * get_str - put a string into a memory block allocated using malloc
 * @s: string
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_str(char *s);

/**
 * add_number - put an integer into a block of memory
 * @n: integer
 *
 * Return: pointer to that memory block, NULL if error
 */
char *add_number(int n);

/**
 * add_arg - put one passed in parameter into a block of memory
 * @type: type of the parameter
 *
 * Return: pointer to the memory block, NULL if error
 */
char *add_arg(char type, ...);

/**
 * conv_binary - converts an unsigned int to binary
 * @n: integer
 *
 * Return: pointer to binary
 */
char *conv_binary(unsigned int n);

/**
 * rev_str - reverse a string
 * @s: string
 * Return: string reversed
 */
char *rev_str(char *s);

/**
 * get_rot13 - rot13 as a string
 * @s: string
 * Return: rot13
 */
char *get_rot13(char *s);

char *str_concat(char *, char *);

char *string_nconcat(char *, char *, unsigned int);

int _strlen(char *);

int _printf(const char *, ...);

char *_strchr(char *s, char c);

int _atoi(char *s);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);


#endif
