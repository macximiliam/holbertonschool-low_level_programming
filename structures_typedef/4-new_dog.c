#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

/**
 * _strlen - Calculates the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
unsigned int _strlen(const char *s)
{
    unsigned int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

/**
 * _strcpy - Copies a string from src to dest
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
    unsigned int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * new_dog - Creates a new dog_t struct
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new struct, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    char *name_copy, *owner_copy;

    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return NULL;

    name_copy = malloc(_strlen(name) + 1);
    if (name_copy == NULL)
    {
        free(new_dog);
        return NULL;
    }
    _strcpy(name_copy, name);

    owner_copy = malloc(_strlen(owner) + 1);
    if (owner_copy == NULL)
    {
        free(name_copy);
        free(new_dog);
        return NULL;
    }
    _strcpy(owner_copy, owner);

    new_dog->name = name_copy;
    new_dog->age = age;
    new_dog->owner = owner_copy;

    return new_dog;
}

/**
 * free_dog - Frees memory allocated for a dog struct
 * @d: Pointer to the dog struct
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        free(d->name);
        free(d->owner);
        free(d);
    }
}
