#include "main.h"

/**
 * _memset - this funtion fills memory with a constant byte.
 * @b: a constant byte.
 * @n: number of bytes.
 * @s: pointers to memory.
 *
 * Return: A pointer to memory area s.
 */
void *_memset(void *s, int c, size_t n)
{
	unsigned int index;
	unsigned char *memory = s, value = c;

	for (index = 0; index < n; index++)
		memory[index] = value;

	return (memory);
}

