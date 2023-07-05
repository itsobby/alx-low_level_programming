#include "main.h"
/**
 *_strlen_recursion - a function that accounts for the length of the string.
 *@s: a pointer variable that points the the string.
 *Return: A recursive call and the length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s != 0)
	{
		return (1 + _strlen_recursion(++s));
	}
	return (0);
}
/**
 *is_palindrome - a function that stores the length of the string in a variable
 *and checks if the length is one 1, if it's 1 it will
 *return 1 which means it's a palindrome.
 *@s: A pointer variable that points the string.
 *Return: The helper function where the length of the
 *string is taken into account and the length - 1
 */
int is_palindrome(char *s)
{
	int length;

	length = _strlen_recursion(s);
	if (length <= 1)
	{
		return (1);
	}
	return (helper(s, length - 1));
}
/**
 *helper - a function that checks each letter in the string
 *to see if they are equal. The ascii value of the character
 *is taken into consideration
 *@length: A variable that has the length of the string stored
 *@s: a pointer that points the the original string
 *Return: Moves through the string.
 */
int helper(char *s, int length)
{
	if (length <= 0)
	{
		return (1);
	}
	else if (*s != s[length])
	{
		return (0);
	}
	else
	{
		return (helper(s + 1, length - 2));
	}
}
