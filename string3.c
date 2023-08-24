#include "shell.h"

/**
 * rev_string - Reverses a string.
 *
 * @s: Input string.
 * Return: No return value.
 */
void rev_string(char *s)
{
	int count = 0, h, n;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (h = 0; h < (count - 1); h++)
	{
		for (n = h + 1; n > 0; n--)
		{
			temp = *(str + n);
			*(str + n) = *(str + (n - 1));
			*(str + (n - 1)) = temp;
		}
	}
}

