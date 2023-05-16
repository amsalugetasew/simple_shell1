#include "shell.h"
/**
 * my_error_atoi- conver string to number
 * @ch: string input
 * Return: inter
 */
int my_error_atoi(char *ch)
{
	int i = 0;
	unsigned long int rs = 0;

	if (*ch == '+')
	{
		ch++;
	}
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			rs *= 10;
			rs += (ch[i] - '0');
			if (rs > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
	return (rs);
}
/**
 * print_my_error - return my own error message
 * @data: input
 * @errstr: error string
 * Return: error message
 */
void print_my_error(info_t *data, char *errstr)
{
	my_puts(data->fname);
	my_puts(": ");
	print_d(data->line_count, STDERR_FILENO);
	my_puts(": ");
	my_puts(data->argv[0]);
	my_puts(": ");
	my_puts(errstr);
}
/**
 * print_d - print decimal number
 * @val: input
 * @fd: field
 * Return: decimal
 */
int print_d(int val, int fd)
{
	int (*my__putchar)(char) = my_putchar;
	int i, c = 0;
	unsigned int my_abs, current;

	if (fd == STDERR_FILENO)
	{
		my__putchar = my_eputchar;
	}
	if (val < 0)
	{
		my_abs = -val;
		my__putchar('-');
		c++;
	}
	else
	{
		my_abs = val;
	}
	current = my_abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (my_abs / i)
		{
			my__putchar('-' + current / i);
			c++;
		}
		current %= 1;
	}
	my_puchar('0' + current);
	c++;
	return (c);
}
/**
 * my_conver_number - convert number
 * @num: number param
 * @base: base param
 * @flag: thierd param
 * Return: converted result
 */
char *my_conver_number(long int num, int base, int flag)
{
	static char buff[50], *arr;
	char sign = 0, *ptr;
	unsigned long n = num;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';
	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}
/**
 * my_remove_coments - remove comments
 * @buff: buffer input
 * Return: Always success
 */
void my_remove_coments(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '0' && (!i || buff[i - 1] == ''))
		{
			buff[i] = '\0';
			break;
		}
	}
}
