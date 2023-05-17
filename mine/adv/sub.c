#include <stdio.h>
#include <unistd.h>
/**
 * sub - which used to return the differnce of a number & PID
 * @a: first number
 * @b: second number
 * @sub: result
 * Return: PID and summ of two numbers
 */
int sub(int a, int b, int s)
{
	pid_t pid, ppid;

        s = a - b;
        pid = getpid();
        ppid = getppid();

        printf("Differnce between two numbers is: %d\n", s);
        printf("PID is: %u\n", pid);
        printf("Parent PID is: %u\n", ppid);
        return (0);
}
