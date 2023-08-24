#include "shell.h"

/**
 * _strdup - Duplicates a string in heap memory.
 *
 * @s: Source string.
 * Return: Duplicated string.
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the length of a string.
 *
 * @s: Input string.
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - Compares characters of strings.
 *
 * @str: Input string.
 * @delim: Delimiter.
 * Return: 1 if characters are equal, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int m, n, p;

	for (m = 0, p = 0; str[m]; m++)
	{
		for (n = 0; delim[n]; n++)
		{
			if (str[m] == delim[n])
			{
				p++;
				break;
			}
		}
	}
	if (m == p)
		return (1);
	return (0);
}

/**
 * _strtok - Splits a string by a delimiter.
 *
 * @str: Input string.
 * @delim: Delimiter.
 * Return: Split string.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int m, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /* Store first address */
		m = _strlen(str);
		str_end = &str[m]; /* Store last address */
	}
	str_start = splitted;
	if (str_start == str_end) /* Reaching the end */
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/* Breaking loop finding the next token */
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/* Replacing delimiter for null char */
		for (m = 0; delim[m]; m++)
		{
			if (*splitted == delim[m])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /* Str != Delim */
			bool = 1;
	}
	if (bool == 0) /* Str == Delim */
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - Defines if string passed is a number.
 *
 * @s: Input string.
 * Return: 1 if string is a number. 0 in other cases.
 */
int _isdigit(const char *s)
{
	unsigned int m;

	for (m = 0; s[m]; m++)
	{
		if (s[m] < 48 || s[m] > 57)
			return (0);
	}
	return (1);
}

