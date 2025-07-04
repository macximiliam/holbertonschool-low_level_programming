#include "lists.h"
#include <stdio.h>

/**
 * list_len - Returns the number of elements in a linkend list
 * @h: pointer at the beginning of the list
 *
 * Return: number of nodes (elements) on the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	for (; h != NULL; count++)
		h = h->next;

	return (count);
}
