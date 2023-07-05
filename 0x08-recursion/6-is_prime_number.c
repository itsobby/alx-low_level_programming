#include "main.h"
/**
 *is_prime_number - a function that checks to see if n is a positive number
 *and calls the helper function
 *@n: The number being compared
 *Return: helper function or 0 if n is less than 0
 */
int is_prime_number(int n)
{
	if (n > 1)
	{
		return (helper_f(n, 2));
	}
	else if (n < 0)
	{
		return (0);
	}
	return (0);
}
/**
 *helper_f - A function that checks if n is a prime number.
 *@n: Takes the income number and compares it
 *@i: The integer that we are iterating through
 *Return: The recursive function
 */
int helper_f(int n, int i)
{
	if (n % i == 0 && i != (n / 2))
	{
		return (0);
	}
	else if (i >= (n / 2))
	{
		return (1);
	}
	else
	{
		return (helper_f(n, i + 1));
	}
}
