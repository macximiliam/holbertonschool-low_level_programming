#ifndef _LISTS_H_
#define _LISTS_H_
#include <stddef.h>

/**
 * struct list_s - singly linked list node
 * @str: dynamically allocated string (typically using strdup)
 * @len: length of the string
 * @next: pointer to the next node in the list, or NULL if it’s the last
 *
 * Description:
 *     Represents a node in a simple singly linked list that holds
 *     a string and its length, and points to the next node.
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
size_t print_list(const list_t *h);
int _putchar(char c);
size_t list_len(const list_t *h);

#endif /*_LISTS_H_*/
