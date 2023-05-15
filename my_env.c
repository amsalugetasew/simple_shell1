#include "shell.h"
/**
 * my_environment - print environment
 * @data: input
 * Return: Always success
 */
int my_environment(info_t *data)
{
	print_str_list(data->env);
	return (0);
}
/**
 * *get_environment- get environment
 * @data: input
 * @name: name param
 * Return: Always success
 */
char *get_environment(info_t *data, const char *name)
{
	list_t *node = data->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *p)
		{
			return (p);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * set_my_environment- set environment
 * @data: input
 * Return: Always success
 */
int set_my_environment(info_t *data)
{
	if (data->argc != 3)
	{
		my_puts("Wrong number of argument\n");
		return (1);
	}
	if (set_environment(data, data->argv[1], data->argv[2]))
	{
		return (0);
	}
	return (1);
}
/**
 * unset_my_environment - unset environment
 * @data: input
 * Return: Always success
 */
int unset_my_environment(info_t *data)
{
	int c;

	if (data->argc == 1)
	{
		my_puts("Too few argument\n");
		return (1);
	}
	for (c = 1; c <= data->argc; c++)
	{
		unset_environment(data, data->argv[1]);
	}
	return (0);
}
/**
 * multi_envList - pupulate list
 * @data: input
 * Return: Always success
 */
int multi_envList(info_t *data)
{
	list_t *node = NULL;
	size_t size;

	for (size = 0; my_env[size]; size++)
	{
		add_node_at_the_end(&node, my_env[size], 0);
	}
	data->env = node;
	return (0);
}
