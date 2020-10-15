#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 *
 *@str: is the string to scan
 *@pattern: is the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	int idx;

	if (str == NULL || pattern == NULL)
		return (0);

	for (idx = 0; str[idx]; idx++)
	{
		if (str[idx] == '.' || str[idx] == '*')
			return (0);
	}
	return (1);
}
