#include "shell.h"
/**
 * my_puts - prints inputs
 * @s: string input
 * Return: Void
 */
void my_puts(char *s)
{
	int i = 0;

	if (!s)
	{
		return;
	}
	while (s[i] != '\0')
	{
		my_putchar(s[i]);
		i++;
	}
}
/**
 * my_putchar - print character
 * @ch: charcter input
 * Return: Always success
 */
int my_putchar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buf[i++] = ch;
	}
	return (1);
}
/**
 * _putfd - write charcter in file directorty
 * @ch: character input
 * @fd: field script
 * Return: Always success
 */
int _putfd(char ch, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buf[i++] = ch;
	}
	return (1);
}
/**
 * _putsfd - print input string
 * @s: char array
 * @fd: file descriptor
 * Return: num of chars
 */
int _putsfd(char *s, int fd)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (*s)
	{
		i += _putfd(*s++, fd);
	}
	return (i);
}
