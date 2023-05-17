#include <stdio.h>
#include <unistd.h>
/**
 * main - returns process ID
 * @void: void argument
 * Return: Parent process ID
 */
int main (void)
{
	printf("%d\n", getppid());
	return (0);
}
