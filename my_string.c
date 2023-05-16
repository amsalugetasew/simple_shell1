#include "shell"
/**
 * my_strlen - find string length
 * @ch: string input
 * Return: length of string
 */
int my_strlen(char *ch)
{
	int c = 0;

	if (!ch)
	{
		return (0);
	}
	while (*ch++)
	{
		c++;
	}
	return (c);
}
/**
 * my_strcmp - compare string return the result
 * @dest: destination string
 * @src: source string
 * Return: compared result
 */
int my_strcmp(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
		{
			return (*dest - *src);
		}
		dest++;
		src++;
	}
	if (*dest == *src)
	{
		return (0);
	}
	else
	{
		return (*dest < *src ? -1 : 1);
	}
}
/**
 * my_starter - check the starter
 * @hy: first input
 * @nd: second input
 * Return: NULL or address of the first char
 */
my_starter(const char *hy, const char *nd)
{
	while (*nd)
	{
		if (*nd++ != *hy++)
		{
			return (NULL);
		}
	}
	return ((char *)hy);
}
/**
 * my_strcat - concatinate and return it
 * @dest: destination param
 * @src: source param
 * Return: concatinated result
 */
char *my_strcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (r);
}
