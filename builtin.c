#include "shell.h"
/**
 * my_history - return the cmd history list
 * @data: input data
 * Return: History list
 */
int my_history(info_t *data)
{
	print_list(data->history);
	return (0);
}
/**
 * my_unset_alias - unset alias
 * @data: input
 * @s: string input
 * Return: alias
 */
int my_unset_alias(info_t *data, char *s)
{
	char *ptr, c;
	int r;

	ptr = my_strchr(s, '=');
	if (!ptr)
	{
		return (1);
	}
	c = *ptr;
	*ptr = 0;
	r = del_node_at_the_index(&(data->alias),
			get_node_index(data->alias, node_starts_with(data->alias,
					s, -1)));
	*ptr = c;
	return (r);
}
/**
 * my_set_alias - set alias and return it
 * @data: input
 * @s: string input
 * Return: always string alias
 */
int my_set_alias(info_t *data, char *s)
{
	char *ptr;

	ptr = my_strchr(s, '=');
	if (!ptr)
	{
		return (1);
	}
	if (!*++ptr)
	{
		return (my_unset_alias(data, s));
	}
	my_unset_alias(data, s);
	return (add_node_at_the_end(&(data->alias), s, 0) == NULL);
}
/**
 * print_alias - print alias
 * @node: node
 * Return: Always success
 */
int print_alias(info_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
		ptr = my_strchr(node->str, '=');
		for (a = node->str; a <= ptr; a++)
		{
			my_putchar(*a);
		}
		my_putchar('\'');
		my_puts(ptr + 1);
		my_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * my_alias - my alias
 * @data: input
 * Return: always success
 */
int my_alias(info_t *data)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (data->argc == 1)
	{
		node = data->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; data->argv[i]; i++)
	{
		ptr = my_strchr(data->argv[i], '=');
		if (ptr)
		{
			my_set_alias(data, data->argv[i]);
		}
		else
		{
			print_alias(node_starts_with(data->alias, data->argv[i], '='));
		}
	}
	return (0);
}

