#include <stdlib.h>
#include "main.h"

/**
 * 
 */
char *_strdup(char *str)
{
    char *copy = NULL;
    int length = 0, i;

    if (str == NULL)
        return (NULL);

    for (; str[length] != '\0'; length++)
        ;


    copy = malloc(sizeof(char) * (length +1));
    if (copy == NULL)
        return NULL;

    for ( i = 0; i < length; i++)
        copy[i] = str[i];

    copy[i] = '\0';

    return (copy);
}