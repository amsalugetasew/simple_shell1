#include<stdio.h>
#define UNUSED(x) (void)(x)
/**
 * main - Return all arguments
 * @ac: first argument
 * @av: second argument
 * Return: All arguments
 */
int main(int ac, char **av)
{
	int i = 0;

	UNUSED(ac);
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
