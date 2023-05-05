#include <stdio.h>
#include "main.h"

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: first number
 * @m: second number that n is to be converted to
 * Return: number of bits that was needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip;
	int timer;

	flip = n ^ m;
	timer = 0;

	while (flip)
	{
		timer++;
		flip &= (flip - 1);
	}

	return (timer);
}
