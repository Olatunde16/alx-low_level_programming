#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @v: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *v)
{
	size_t s = 0;

	while (v)
	{
		if (!v->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", v->len, v->str);
		v = v->next;
		s++;
	}

	return (s);
}
