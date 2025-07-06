#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all the elements of a doubly linked list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: The number of nodes printed.
 *
 * Description:
 * Iterates through the list, printing each node's integer value and
 * counting the total number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	for (; h != NULL; h = h->next, count++)
	{
		printf("%d\n", h->n);
	}
	return (count);
}

