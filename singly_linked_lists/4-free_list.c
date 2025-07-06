#include <stdlib.h>
#include "lists.h"


/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 *
 * Description: Traverses a singly linked list and frees
 * each node’s string and the node itself to prevent memory leaks.
 * The function safely handles an empty list (head == NULL).
 *
 * Return: void
 */
void free_list(list_t *head)
{
	for (; head != NULL; head = head->next)
	{
		free(head->str);
		free(head);
	}

}
