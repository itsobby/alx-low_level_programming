#include "main.h"
/**
 *_pow_recursion - writing a funciton that returns
 *the value of x raised to y.
 *@x: Number being raised to the power of y
 *@y: Representation of power
 *Return: Returns the product of x raised to y.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (x == 1 || y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
