#include <stdio.h>
#include <unistd.h>
/**
 * add - which used to return addtion of a number & PID
 * @a: first number
 * @b: second number
 * @sum: result
 * Return: PID and summ of two numbers
 */
int add(int a, int b, int sum)
{
	pid_t pid, ppid;

	sum = a + b;
	pid = getpid();
	ppid = getppid();

	printf("Sum of two numbers is: %d\n", sum);
	printf("PID is: %u\n", pid);
	printf("Parent PID is: %u\n", ppid);
	return (0);
}
