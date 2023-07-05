#include "main.h"
/**
 *_strlen_recursion - Function that returns the length of a string
 *@s: A pointer variable that points to variable that stores a string
 *Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	int i;

	i = 0;
	if (*s != 0)
	{
		i++;
		return (i + _strlen_recursion(s + 1));
	}
	return (*s);
}
