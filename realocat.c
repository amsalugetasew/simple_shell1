#include "shell.h"
/**
 * my_memset - set memory
 * @s: first param
 * @b: second param
 * @n: third param
 * Return: set memory
 */
char *my_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
/**
 * ffree - free it
 * @ptr: pointer param
 * Return: freee
 */
void ffree(char **ptr)
{
	char **a = ptr;

	if (!ptr)
	{
		return;
	}
	while (*ptr)
	{
		free(*ptr++);
	}
	free(a);
}
/**
 * *my_realloc - reallocate mem
 * @ptr: ptr param
 * @old_seze: size1
 * @new_size: size2
 * Return: pointer
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	p = malloc(new_size);
	if (!p)
	{
		return (NULL);
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		p[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (p);
}
