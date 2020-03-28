#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *is_palindrome - checks whether or not a given integer is a palindrome
 *
 *@n: number to be checked
 *
 *Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long revNum = 0, aux = n, dig = 0;

	while (aux != 0)
	{
		dig = aux % 10;
		revNum = revNum * 10 + dig;
		aux = aux / 10;
	}

	if (n == revNum)
		return (1);

	return (0);
}
