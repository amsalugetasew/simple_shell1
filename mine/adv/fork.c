#include <stdio.h>
#include <unistd.h>
/**
 * main - forking
 * @void: void
 * Return: fork functtion
 */
int main(void)
{
	pid_t pid;

	fork();
	if (fork() == -1)
	{
		printf("Unsuccessful\n");
		return (-1);
	}
	if (fork() == 0)
	{
		sleep(4);
		printf("I am child!\n");
	}
	else
	{
		printf("I am parent\n");
	}	
	return (0);
}
