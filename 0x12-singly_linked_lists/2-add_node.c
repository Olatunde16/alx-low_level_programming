#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the addresss of the new element, or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *create;
	unsigned int len = 0;

	while (str[len])
		len++;

	create = malloc(sizeof(list_t));
	if (!create)
		return (NULL);

	create->str = strdup(str);
	create->len = len;
	create->next = (*head);
	(*head) = create;

	return (*head);
}
