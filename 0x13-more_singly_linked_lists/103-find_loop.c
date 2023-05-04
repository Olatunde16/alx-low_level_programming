#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *on = head;
	listint_t *off = head;

	if (!head)
		return (NULL);

	while (on && off && off->next)
	{
		off = off->next->next;
		on = on->next;
		if (off == on)
		{
			on = head;
			while (on != off)
			{
				on = on->next;
				off = off->next;
			}
			return (off);
		}
	}

	return (NULL);
}
