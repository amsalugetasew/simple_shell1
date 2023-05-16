#include "shell.h"
/**
 * main - Main program
 * @argc: first argument
 * @argv: second argument
 * Return: hello world
 */
int main(int argc, char *argv[])
{
	info_t data[] = {INFO_INIT};
	int fd = 2;

	asm("mov, %1, %0\n\t"
			"add $3, $0"
			: "-r" (fd)
			: "r" (fd));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
			{
				exit(120);
			}
			if (errno == ENOENT)
			{
				my_puts(argv[0]);
				my_puts(": 0: Can't open ");
				my_puts(argv[1]);
				my_putchar('\n');
				my_putcahr(BUF_FLUSH);
				exit(122);
			}
			return (EXIT_FAILURE);
		}
		data_readfd = fd;
	}
	multi_envList(data);
	read_history(data);
	hsh(data, argv);
	return (EXIT_SUCCESS);
}
