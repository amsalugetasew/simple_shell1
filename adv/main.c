int sub(int n1, int n2, int s);
int add(int n1, int n2, int sum);
/**
 * main - main function
 * @void: void parm
 * Return: always sucess
 */
int main(void)
{
	int a = 30, b = 10, sum = 0, s = 0;

	add(a, b, sum);
	sub(a, b, s);
	return (0);
}
