#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{ 
    int a = 0;

    for (; s[a]; a++)
    ;

    return(a);
}