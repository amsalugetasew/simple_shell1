#include <stdlib.h>
#include <stdio.h>
/**
 * main - return text values in a file using getline function
 * @void: void parameter
 * Return: All text value
 */
int main(void)
{
	int bytes_read;
	size_t s = 10;
	char *str;

	printf("Please enter a string: ");
	str = (char *)malloc(s);
	bytes_read = getline(&str, &s, stdin);
	if (bytes_read == -1)
	{
		printf("ERROR!");
	}
	else
	{
		printf("The output string is: %s\n", str);
		printf("Current size for string block: %d\n", bytes_read);
	}
	return (0);
}
