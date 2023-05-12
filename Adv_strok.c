#include <stdio.h>
#include <string.h>
/**
 * main - Return without strtok
 *
 * Return: strings without strtok
 */
int main()
{
	char *ch = "my is my first phrase without strtok,this is my second phrase without strtok";
	int len = strlen(ch), i;
	/*char *ch1 = " ";*/

	for (i = 0; i < len; i++)
	{
		/*ch1[i] = ch[i];*/
		if (ch[i] == ',')
		{
			printf("\n");
		}
		else
		{
			printf("%c", ch[i]);
		}
	}
	printf("\n");
	return (0);
}
