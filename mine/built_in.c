#include "shell.h"
/**
 * _myexit - cmd of exit
 * @data: pointer param
 * Return: exit
 */
int _myexit(info_t *data)
{
	int check;

	if (data->argv[1])
	{
		check = my_erratoi(data->argv[1]);
		if (check == -1)
		{
			data->status = 2;
			print_erro(data, "Illegal number: ");
			my_puts(data->argv[1])0;
			my_putchar("\n");
			return (1);
		}
		data->err_num = my_erratoi(data->argv[1]);
		return (-1);
	}
	data->err_num = -1;
	return (-1);
}
/**
 * _mycd - my change directory builtin command
 * @data: pointer
 * Return: Always 0
 */
int _mycd(info_t *data)
{
	int ch_r;
	char *s, *dir, buff[1024];

	s = getcwd(buff, 1024);
	if (!s)
	{
		my_puts("TODO: >>getcwd failer message here\n");
	}
	if (!data->argv[1])
	{
		dir = get_my_env(data, "HOME");
		if (!dir)
		{
			ch_r = chdir((dir = get_my_env(data, "PWD=")) ? dir : "/");
		}
		else
		{
			ch_r = chdir(dir);
		}
	}
	else if (my_strcmp(data->argv[1], "-") == 0)
	{
		if (!get_my_env(data, "OLDPWD"))
		{
			my_puts(s);
			my_putchar('\n');
			return (1);
		}
		my_puts(get_my_env(data, "OLDPWD")), my_putchar('\n');
		ch_r = ((get_my_env(data, "OLDPWD")) ? dir : "/");
	}
	else
	{
		ch_r = chdir(dat->argv[1]);
	}
	if (ch_r == -1)
	{
		print_error(data, "can't cd to ");
		my_puts(data->argv[1]), my_putchar('\n');
	}
	else
	{
		my_set_env(data, "OLDPWD", get_my_env(data, "PWD="));
		my_set_env(data, "PWD", getcwd(beff, 1024));
	}
	return (0);
}
/**
 * _myhelp - help of my shell cmd
 * @data: pointer param
 * Return: Always 0
 */
int _myhelp(info_t *data)
{
	char **arg_arr;

	arg_arr = data->argv;
	my_puts("help call works. function not yet implemented \n");
	if (0)
	{
		my_puts(*arg_arr);
	}
	return (0);
}
