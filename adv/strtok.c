#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - return token strings using specified dilimiters
 * @void: void
 * Return: return tokes
 */
int main(void)
{
	char *string = "This is my string on shell project";
	char *str = malloc(sizeof(char) * strlen(string));
	char *dilm = " ", *token;
	int i = 0;

	strcpy(str, string);
	token  = strtok(str, dilm);
	while (token)
	{
		printf("Token at index [%d] %s %s\n", i, "is: ", token);
		token = strtok(NULL, dilm);
		i++;
	}
	return (0);
}
