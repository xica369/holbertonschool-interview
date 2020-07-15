#include "holberton.h"

int main(int argc, char *argv[])
{
	char error[] = "Error\n";
	int cont;

	if (argc != 3)
	{
		for (cont = 0; cont <= 5; cont++)
			_putchar(error[cont]);
		exit(98);
	}
}
