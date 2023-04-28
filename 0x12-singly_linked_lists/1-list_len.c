#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @v: pointer to the list_t list
 *
 * Return: number of elements in v
 */

size_t list_len(const list_t *v)
{
	size_t n = 0;

	while (v)
	{
		n++;
		v = v->next;
	}
	return (n);
}
