#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int g;
	int h;

	for (g = 0; dest[g] != '\0'; g++)
		;

	for (h = 0; src[h] != '\0'; h++)
	{
		dest[g] = src[h];
		g++;
	}

	dest[g] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies the string pointed to by src.
 *
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * Return: An integer less than, equal to, or greater than zero
 *         if s1 is found, respectively, to be less than, to match,
 *         or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int g;

	for (g = 0; s1[g] == s2[g] && s1[g]; g++)
		;

	if (s1[g] > s2[g])
		return (1);
	if (s1[g] < s2[g])
		return (-1);
	return (0);
}

/**
 * _strchr - Locates a character in a string.
 *
 * @s: String to be searched.
 * @c: Character to be found.
 * Return: Pointer to the first occurrence of the character c,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int g = 0;

	for (; *(s + g) != '\0'; g++)
		if (*(s + g) == c)
			return (s + g);
	if (*(s + g) == c)
		return (s + g);
	return ('\0');
}

/**
 * _strspn - Gets the length of a prefix substring.
 *
 * @s: Initial segment.
 * @accept: Accepted bytes.
 * Return: The number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int g, h, bool;

	for (g = 0; *(s + g) != '\0'; g++)
	{
		bool = 1;
		for (h = 0; *(accept + h) != '\0'; h++)
		{
			if (*(s + g) == *(accept + h))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (g);
}

