#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - Frees a dlistint_t doubly linked list
 * @head: Pointer to the head of the list
 *
 * Description: Iterates through the list and frees each node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	for (; head != NULL; head = temp)
	{
		temp = head->next;
		free(head);
	}
}
