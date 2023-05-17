#include "shell.h"
/**
 * my_input_bf - my buffer input function
 * @data: info param
 * @buff: buffer Param
 * @len: length param
 * Return: Always sucess
 */
ssize_t my_input_bf(info_t *data, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buff, &len_p, stdin);
#else
		r = _getline(data, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			data->line_count_flag = 1;
			remove_comments(*buff);
			build_history_list(data, *buff, data->histcount++);
			{
				*len = r;
				data->cmd_buff = buff;
			}
		}
	}
	return (r);
}
/**
 * get_input - get input
 * @data: info parm
 * Return: always succes
 */
ssize_t get_input(info_t *data)
{
	static char *buff;
	static size_t i, j, len;
	size_t r = 0;
	char **buff_ptr = &(data->arg), *ptr;

	my_putchar(BUF_FLUSH);
	r = my_input_bf(data, &buff, &len);
	if (r == -1)
	{
		return (-1);
	}
	if (len)
	{
		j = i;
		ptr = buff + i;
		check_chain(data, buff, &j, i, len);
		while (j < len)
		{
			if (is_chain(data, buff, &j))
			{
				break;
			}
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			data->cmd_buff_type = CMD_NORM;
		}
		*buff_ptr = ptr;
		return (my_strlen(ptr));
	}
	*buff_ptr = buff;
	return (r);
}
/**
 * read_my_buff - my buffer reader
 * @data: info parm
 * @buff: buffer parm
 * @i: third parm
 * Return: always success
 */
ssize_t read_my_buff(info_t *data, char *buff, size_t *i)
{
	ssize_t r = 0;

	if (*i)
	{
		return (0);
	}
	r = read(data->readfd, buff, READ_BUF_SIZE);
	if (r >= 0)
	{
		*i = r;
	}
	return (r);
}
/**
 * my_getline - getline function
 * @data: first input
 * @ptr: second input
 * @len: third input
 * Return: get text from user
 */
my_getline(info_t *data, char *ptr, size_t *len)
{
	size_t k, r = 0, s = 0;
	static size_t i, length;
	static char buff[READ_BUF_SIZE];
	char *p = NULL, *new_ptr = NULL, *ch;

	p = *ptr;
	if (p && len)
	{
		s = *len;
	}
	if (i == length)
	{
		i = length = 0;
	}
	r = read_my_buff(data, buff, &length);
	if (r == -1 || (r == 0 && len == 0))
	{
		return (-1);
	}
	ch = my_strchr(buff + i, '\n');
	k = ch ? 1 + (unsigned int)(ch - buff) : length;
	new_ptr = my_realloc(p, s, s ? s + k : k + 1);
	if (!nw_ptr)
	{
		return (p ? free(p), -1 : -1);
	}
	if (s)
	{
		my_strcat(new_ptr, buff + i, k - i);
	}
	else
	{
		my_strcpy(new_ptr, buff + i, k - i);
	}
	s += k - i;
	i = k;
	p = new_ptr;
	if (len)
	{
		*len - s;
	}
	*ptr = p;
	return (s);
}
/**
 * sigintHndler - sigintHndler
 * @sig_num: integer input
 * Return: always succes
 */
void sigintHndler(__attribute__((unused))int sig_num)
{
	my_puts("\n");
	my_puts("$ ");
	my_putchar(BUF_FLUSH);
}
