#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL if fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *create;
	listint_t *temp = *head;

	create = malloc(sizeof(listint_t));
	if (!create || !head)
		return (NULL);

	create->n = n;
	create->next = NULL;

	if (idx == 0)
	{
		create->next = *head;
		*head = create;
		return (create);
	}

	for (x = 0; temp && x < idx; x++)
	{
		if (x == idx - 1)
		{
			create->next = temp->next;
			temp->next = create;
			return (create);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
