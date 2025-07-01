Singly Linked Lists in C
This project contains my implementation of a simple singly linked list (list_t) in C, following the Betty style. It compiles cleanly on Ubuntu 20.04 using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89

When to Use Linked Lists vs Arrays
Arrays
Provide O(1) random access.

Require a fixed size or expensive resizing.

Linked Lists

Dynamically sized; nodes can be inserted/deleted in O(1) if position is known.

No need to shift elements—great for frequent insertions/removals.

Sequential access only (O(n) to reach the nth element).

Require extra memory per node (for next-pointer) and suffer from poor cache locality. 

Use arrays when fast indexing and cache performance matter; use linked lists when data changes often and dynamic size is essential.

My list_t Structure
c
Copiar
Editar
typedef struct list_s
{
    char *str;              /* dynamically allocated string */
    unsigned int len;       /* length of the string */
    struct list_s *next;    /* pointer to the next node */
} list_t;
str: allocated with malloc/strdup

len: stores strlen(str) for printing/management

next: links to the next node, or NULL if it's the last

Key Requirements
No global variables; each file contains ≤ 5 functions.

Only use: malloc, free, exit, _putchar, and for print_list, printf.

Strict adherence to Betty style (checked via betty-style.pl, betty-doc.pl).

lists.h includes all function prototypes and _putchar, with proper include guards.

Implemented Functions
print_list – prints each node as [len] str\n, or [0] (nil)\n if str == NULL; returns the number of nodes.

list_len – counts and returns the total number of nodes.

add_node – inserts a new node at the beginning; duplicates str with strdup.

add_node_end – inserts a new node at the end; also uses strdup.

free_list – properly frees all nodes and their strings to prevent memory leaks.

How to Compile and Test
For example, to test print_list:


gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-print_list.c 0-main.c -o a
./a
(I do NOT include main.c in the repo; the evaluator uses its own test files.)

References Consulted
Comparison between arrays and linked lists: GeeksforGeeks 
en.wikipedia.org
+10
geeksforgeeks.org
+10
geeksforgeeks.org
+10

Discussion on use cases for linked lists: Stack Overflow 
stackoverflow.com