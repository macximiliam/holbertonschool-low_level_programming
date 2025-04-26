#include "main.h"

/**
 * 
 */
void puts2(char *str)
{
    int i = 0;
    for (; str [i]; i++)
    {
        if (i %2 == 0)
            _putchar(str [i]);
    }
        _putchar('\n');
}