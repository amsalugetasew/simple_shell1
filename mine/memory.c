#include "shell.h"
/**
 * bfree - free memory
 * @ptr: pointer
 * Return: Always 0
 */
bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
