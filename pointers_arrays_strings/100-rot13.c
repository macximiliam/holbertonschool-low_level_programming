#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: The string to encode.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M')) ||
            ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))) 
        {
            if (s[i] >= 'a' && s[i] <= 'm')
                s[i] += 13;
            else if (s[i] >= 'A' && s[i] <= 'M')
                s[i] += 13;
            else if (s[i] >= 'n' && s[i] <= 'z')
                s[i] -= 13;
            else if (s[i] >= 'N' && s[i] <= 'Z')
                s[i] -= 13;
        }
    }

    return (s);
}
