#include "shell.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the input str
 * @buff: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buff, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFFSIZE)
			*n = j;

		else
			*n = BUFFSIZE;
		*lineptr = buff;
	}
	else if (*n < j)
	{
		if (j > BUFFSIZE)
			*n = j;
		else
			*n = BUFFSIZE;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}
/**
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buff;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buff = malloc(sizeof(char) * BUFFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFFSIZE)
			buff = _realloc(buff, input, input + 1);
		buff[input] = t;
		input++;
	}
	buff[input] = '\0';
	bring_line(lineptr, n, buff, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
