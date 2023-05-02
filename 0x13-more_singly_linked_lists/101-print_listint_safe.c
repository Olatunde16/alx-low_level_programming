#include "lists.h"

/**
 * print_listint_safe - function that prints a linked list with a loop safely.
 * @head: pointer to the 1st node of the linked list
 *
 * Return: created_node (create_n), exits 98 if it fails
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp_n = NULL;
	const listint_t *active_n = NULL;
	size_t counter = 0;
	size_t create_n;

	tmp_n = head;
	while (tmp_n)
	{
		printf("[%p] %d\n", (void *)tmp_n, tmp_n->n);
		counter++;
		tmp_n = tmp_n->next;
		active_n = head;
		create_n = 0;
		while (create_n < counter)
		{
			if (tmp_n == active_n)
			{
				printf("-> [%p] %d\n", (void *)tmp_n, tmp_n->n);
				return (counter);
			}
			active_n = active_n->next;
			create_n++;
		}
		if (!head)
			exit(98);
	}
	return (counter);
}
