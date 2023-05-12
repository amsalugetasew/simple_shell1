#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - read text without getline function
 * @void: void parameter
 * Return: Return text to t
 */
int main(void)
{
	size_t size = 10;
	char *str;

	printf("please enter string: ");
	str = (char *)malloc(size);
	scanf("%[^\n]s", str);
	size = strlen(str) + 1;
	printf("The input string is: %s\n", str);
	printf("The memory block size of current string is: %ld\n", size);
	return (0);
}
