#include "main.h"

/** * _strncat - Concatenates two strings using at most n bytes of src.                                                 * @dest: The destination string.
 * @src: The source string.                               * @n: The maximum number of bytes to use from src.
 * * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
        char *dest_start = dest;

        while (*dest)
        {
                dest++;
        }

        while (n-- && (*dest++ = *src++))
                ;

        *dest = '\0';

        return (dest_start);
}
