#include <stdio.h>
#include "main.h"

/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: pointer to the decimal number to change
 * @index: index position to change
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int clear;
	unsigned int get;

	if (index > 64)
		return (-1);
	get = index;
	for (clear = 1; get > 0; clear *= 2, get--)
		;

	if ((*n >> index) & 1)
		*n -= clear;

	return (1);
}
