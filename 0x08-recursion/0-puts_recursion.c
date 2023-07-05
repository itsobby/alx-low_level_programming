#include  "main.h"
/**
 *_puts_recursion - A function that prints a string followed by a new line
 *@s: A pointer that points to what's being passed in.
 *
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
	}
	else
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
}
