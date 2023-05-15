#include "shell.h"
/**
 * *my_strcpy - copy strings
 * @dest: distnation
 * @str: source
 * @n: length of char
 * Return: copied string
 */
char *my_strcpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (str[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 * *my_strcat - my string concatinator function
 * @dest: distination
 * @src: source
 * @n: character size
 * Return: concatinaed string
 */
char *my_strcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
	{
		dest[i] = '\0';
	}
	return (s);
}
/**
 * *my_strchr - used to search the first occurance of character
 * @s: input string
 * @ch: charater to be searched
 * Return: string
 */
char *my_strchr(char *s, char ch)
{
	do {
		if (*s == ch)
		{
			return (s);
		}
	} while (*s++ != '\0');
	return (NULL);
}
