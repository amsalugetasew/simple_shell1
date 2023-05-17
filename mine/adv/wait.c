#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
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
                printf("I am child!\n");
        }
        else
        {
		wait(NULL);
		sleep(30);
                printf("I am parent\n");
        }
        return (0);
}
