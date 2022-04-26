#include "main.h"
/**
 * _memset - fills memory with a constant byte,
 * @m: memory area.
 * @a: constant byte.
 * @t: bytes filled.
 * Return: the pointer to dest.
 */
char *_memset(char *m, char a, unsigned int t)
{
	unsigned int n;

	for (n = 0; n < t; n++)
		*(m + n) =  t;

	return (m);
}
