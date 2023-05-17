#include "shell.h"
/**
 * clear_info - initialize info
 * @data: pointer
 * Return: void
 */
void clear_info(info_t *data)
{
	data->arg = NULL;
	data->argv = NULL;
	data->path = NULL;
	data->argc = 0;
}
/**
 * set_info - set info
 * @data: pointer param
 * @av: second pointer param
 * Return: void
 */
void set_info(info_t *data, char **av)
{
	int i = 0;

	data->fnmae = 
