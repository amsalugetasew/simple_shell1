#include "shell.h"
/**
 * my_len_list  - specifiy len of linked list
 * @h: pointer input
 * Return: len of list
 */
size_t my_len_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * my_list_to_strings - list strings
 * @head: pointer inpu
 * Return: string list
 */
char **my_list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs, *str;

	if (!head || !i)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
	{
		return (NULL);
	}
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(my_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
			{
				free(strs[j]);
			}
			free(strs);
			return (NULL);
		}
		str = my_strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
/**
 * print_list - print lists
 * @h: pointer input
 * Return: list
 */
size_t print_list
{
	size_t i = 0;

	while (h)
	{
		my_puts(convert_number(h->num, 10, 0));
		my_putchar(":");
		my_putchar(' ');
		my_puts(h->str ? h->str : "(nil)");
		my_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * *node_starts_with - find node starter
 * @node: pointer param
 * @prefx: point param2
 * @ch: char param
 * Return: node starter
 */
list_t *node_starts_with(list_t *node, char *prefx, char ch)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = starts_with(node->str, prefx);
		if (ptr && ((ch == -1) || (*ptr == ch)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_at_the_index - find node at the specified index
 * @head: pointer param
 * @node: second pointer param
 * Return: node for a specifed index
 */
ssize_t get_node_at_the_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
		{
			return (i);
		}
		head = head->next;
		i++;
	}
	return (-1);
}
