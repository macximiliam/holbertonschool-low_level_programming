#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a singly linked list
 * @head: pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new node, or NULL if memory allocation fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	if (head == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(new->str);
	new->next = *head;
	*head = new;

	return (new);
}
