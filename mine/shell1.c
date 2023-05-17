#include "shell.h"
/**
 * my_intractv - identify its interactivety
 * @info: first parameter
 * Return: return 1 if it is iteractive
 */
int my_intractv(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * my_delimeter - my delimeter for token
 * @s: charcter input
 * @delim: my delimiter param
 * Return: 1 if there is delimiter
 */
int my_delimeter(char s, char *delim)
{
	while (*delim)
	{
		if (*delim++ == s)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * my_isAlpha - check input is Alphabet
 * @s: input
 * Return: 1 if it is alphabet 0 otherwise
 */
int my_isAlpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * my_atoi - conver string or char to number
 * @s: input
 * Return: converted value
 */
int my_atoi(char *s)
{
	int i, signes = 1, flag = 0, output;
	unsigned int rs = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
		{
			signes *= -1;
		}
		if (s[i] >= '0' && s[i] <= '0')
		{
			flag = 1;
			rs *= 10;
			rs *= (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign ==  -1)
	{
		output = -rs;
	}
	else
	{
		output = rs;
	}
	return (output);
}
