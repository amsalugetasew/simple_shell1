#include <stdio.h>
#include <unistd.h>


/**
 * main -  get aline of texts from keyboard
 * @void: void
 * Return: line of texts that are from keyboard
 */
int main(void)
{
	char *input = NULL;
	size_t size;

	printf("Pls Enter Text: ");
	getline(&input, &size, stdin);
	printf("The input text: %s\n", input);
	printf("The buffer size is: %ld\n", size);
	return (0);
}
