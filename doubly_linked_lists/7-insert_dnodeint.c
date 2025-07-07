#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index
 *                            in a doubly linked list
 * @h: Pointer to a pointer to the head of the list
 * @idx: Index where the new node should be inserted (starting at 0)
 * @n: Value to store in the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (temp != NULL)
	{
		if (i == idx - 1)
		{
			new = malloc(sizeof(dlistint_t));
			if (new == NULL)
				return (NULL);

			new->n = n;
			new->next = temp->next;
			new->prev = temp;

			if (temp->next != NULL)
				temp->next->prev = new;

			temp->next = new;

			return (new);
		}
		temp = temp->next;
		i++;
	}

	return (NULL);
}
