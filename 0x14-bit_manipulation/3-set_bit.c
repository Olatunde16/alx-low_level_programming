#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at a given index
 * @n: decimal number passed by pointer
 * @index: index position to change, starting from 0
 * Return: 1 if it worked, -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int set;

	if (index > 64)
		return (-1);

	for (set = 1; index > 0; index--, set *= 2)
		;
	*n += set;

	return (1);
}
