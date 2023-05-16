/**
 * get_my_env -get the envirnonment lsit\
 * @data: input
 * Return: list of env
 */
char **get_my_env(info_t *data)
{
	if (!data->env || data->env_changed)
	{
		data->environ = list_to_strings(data->env);
		data->env_changed = 0;
	}
	return (data->environ);
}
/**
 * my_unsetenv - unset envi
 * @data: input
 * @var: variable param
 * Return: unseted envi
 */
int my_unsetenv(info_t *data, char *var)
{
	list_t *node = data->env;
	size_t i = 0;
	char *ptr;

	if (!node || !var)
	{
		return (0);
	}
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			data->env_changed = del_node_at_the_index(&(data->env), i);
			i = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (data->env_changed);
}
/**
 * my_set_env -set my env
 * @data: input
 * @var: var param
 * @val: val param
 * Return: seted env
 */
int my_set_env(info_t *data, char *var, char *val)
{
	char *buff = NULL, *ptr;
	list_t *node;

	if (!var || !val)
	{
		return (0);
	}
	buff = malloc(my_strlen(var) * my_strlen(avl) +2);
	if (!buff)
	{
		return (1);
	}
	my_strcpy(buff, var);
	my_starcat(buff, "=");
	my_strcat(buff, val);
	node = data->env;
	while (node)
	{
		ptr = strats_with(node->str, var);
		if (ptr && *ptr == '=')
		{
			free(node->str);
			node->str = buff;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_at_the_end(&(data->env), buff, 0);
	free(buff);
	data->env_changed = 1;
	return (0);
}
