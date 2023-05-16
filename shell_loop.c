#include "shell.h"
/**
 * hsh - main shell loop
 * @data: pointer param
 * @argv: string param
 * Return: 0 on success 1 otherwise
 */
int hsh(info_t *data, char *argv[])
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -1)
	{
		clear_info(data);
		if (interactive(data))
		{
			my_puts("$ ");
		}
		my_eputchar(BUF_FLUSH);
		r = get_inpu(data);
		if (r != -1)
		{
			set_info(data, argv);
			builtin_ret = find_builtin(data);
			if (builtin_ret == -1)
			{
				find_cmd(data);
			}
		}
		else if (interactive(data))
		{
			my_putchar('\n');
		}
		free_info(data, 0);
	}
	write_history(data);
	free_info(data, 1);
	if (!interactive(data) && data->status)
	{
		exit(data->status);
	}
	if (builtin_ret == -1)
	{
		if (data->err_num == -1)
		{
			exit(data->status);
		}
		exit(data->err_num);
	}
	return (builtin_ret);
}
/**
 * find_builtin - find builtine result
 * @data: pointer param
 * Return: builtine
 */
int find_builtin(info_t *data)
{
	int i, built_in_ret = -1;

	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", my_set_env},
		{"unsetenv", my_unset_env},
		{"cd", _mycd},
		{"alias", my_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (my_strcmp(data->argv[0], builtintbl[i].type) == 0)
		{
			data->line_count++;
			built_in_ret = builtintbl[i].func(data);
			break;
		}
	}
	return (built_in_ret);
}
/**
 * find_cmd - return cmd
 * @data: pointer param
 * Return: return cmd
 */
void find_cmd(info_t *data)
{
	char *path = NULL;
	int i, k;

	data->path = data->argv[0];
	if (data->linecount_flag == 1)
	{
		data->line_count++;
		data->linecount_flag = 0;
	}
	for (i = 0, k = 0; data->arg[i]; i++)
	{
		if (!is_delim(data->arg[i], " \t\n"))
		{
			k++;
		}
	}
	if (!k)
	{
		return;
	}
	path = find_path(data, get_my_env(data, "PATH"), data->argv[0]);
	if (path)
	{
		data->path = path;
		fork_cmd(data);
	}
	else
	{
		if ((interactive(data) || get_my_env(data, "PATH") || data->argv[0][0] == '/') && is_cmd(data, data->argv[0]))
		{
			fork_cmd(data);
		}
		else if (*(data->arg) != '\n')
		{
			data->status = 122;
			print_error(data, "not found\n");
		}
	}
}
/**
 * fork_cmd - call cmd
 * @data: pointer param
 * Return: void
 */
void fork_cmd(info_t *data)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(data->path, data->argv, get_environ(data)) == -1)
		{
			free_info(data, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(data->status));
		if (WIFEXITED(data->status))
		{
			data->status = WEXITSTATUS(data->status);
			if (data->status == 126)
			{
				print_error(data, "Permission denied\n");
			}
		}
	}
}
