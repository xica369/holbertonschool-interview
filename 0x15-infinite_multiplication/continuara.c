#include "holberton.h"


void multiply_string(char *num1, char *num2, int len1, int len2)
{
	int **result;
	int cont = 0, i_n2 = 0, i = 0, carry = 0, n1 = 0, j, n2, sum = 0;

	result = malloc((len1 + len2) * sizeof(char));
	if (result == NULL)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	cont = len1 + len2;
	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		i_n2 = 0;
		carry = 0;
		cont--;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + carry + result[cont - i_n2];
			carry = sum / 10;
			result[cont - i_n2] = (sum % 10);
			i_n2++;
		}
		if (carry > 0)
			result[cont - i_n2 - 1] =  ((result[cont - i_n2 - 1] - '0') + carry);

	}
	i = cont - i_n2;
	for (i = 0; i < len1 + len2; i++)
		_putchar(result[i]);
}


int check_digits(char *num)
{
	int cont, flag_zero = 1;

	for (cont = 0; num[cont]; cont++)
	{
		if (num[cont] < '0' || num[cont] > '9')
			raise_error();

		if (num[cont] != '0')
			flag_zero = 0;
	}
	if (flag_zero == 1)
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}

	return (cont);
}

void raise_error(void)
{
	char error[] = "Error\n";
	int cont;

	for (cont = 0; cont <= 5; cont++)
		_putchar(error[cont]);
	exit(98);
}

int main(int argc, char *argv[])
{
	int len1 = 0, len2 = 0;
	char *num1, *num2;

	if (argc != 3)
		raise_error();

	len1 = check_digits(argv[1]);
	len2 = check_digits(argv[2]);

	num1 = len1 > len2 ? argv[1] : argv[2];
	num2 = len1 > len2 ? argv[2] : argv[1];

	multiply_string(num2, num1, len2, len1);
	return (0);
}
