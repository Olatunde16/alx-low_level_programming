#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: char string
 * Return: the converted number, or 0 if there are unconvertable chars
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int sum, exp;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (exp = 1, sum = 0, len--; len >= 0; len--, exp *= 2)
	{
		if (b[len] == '1')
			sum += exp;
	}

	return (sum);
}
