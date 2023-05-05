#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks endianness
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int anynum;

	anynum = 1;
	if (*(char *)&anynum == 1)
		return (1);
	else
		return (0);
}
