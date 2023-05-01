#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @v: Linked list of type listint_t to print
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *v)
{
	size_t num = 0;

	while (v)
	{
		printf("%d\n", v->n);
		num++;
		v = v->next;
	}

	return (num);
}
