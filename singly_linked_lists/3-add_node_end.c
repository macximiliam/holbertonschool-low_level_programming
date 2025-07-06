#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * str_len - calculates the length of a string
 * @s: pointer to the null-terminated string
 *
 * Return: number of characters before the terminating null byte
 */
static unsigned int str_len(const char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * add_node_end - adds a node at the end of a singly linked list
 * @head: pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;

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

	new->len = str_len(new->str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}

	return (new);
}
