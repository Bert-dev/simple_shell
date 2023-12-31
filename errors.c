#include "shell.h"
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putsfd - prints an input string
 * @str: string to be printed
 * @fd: file descriptor
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _putfd - writes the character c to given fd
 * @c: character to print
 * @fd: fil descriptor
 * Return: -1 on error, 1 on success
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *  _eputchar - writes the character c to stderr
 *  @c: character to input
 *  Return: on success 1
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	write(2, buf, i);
	i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
