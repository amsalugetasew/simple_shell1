#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - create an execv file
 * @void: void
 * Return: Create an excutable file
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-1", NULL};
	int val = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("ERROR!");
		return (-1);
	}
	if (pid == 0)
	{
		val = execve("./add", argv, NULL);
		if (val == -1)
		{
			perror("ERROR!");
		}
	}
	else
	{
		wait(NULL);
		printf("Everything is Aright\n");
	}
	return (0);
}
