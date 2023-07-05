#include "main.h"
/**
 *_sqrt_recursion - A function that returns the natural
 *square root of a number.
 *
 *@n: The number that you want to find the square root of.
 *Return: The square root of the number.
 */
int _sqrt_recursion(int n)
{
	return (helper_sqrt(n, 0));
}
/**
 *helper_sqrt - A function that checks if a number is a natural square root.
 *@n: The input from main function.
 *@i: The number multiplied by itself.
 *Return: Finding the square of the number.
 */
int helper_sqrt(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	else if (i * i > n)
	{
		return (-1);
	}
	else
	{
		return (helper_sqrt(n, i + 1));
	}
}
