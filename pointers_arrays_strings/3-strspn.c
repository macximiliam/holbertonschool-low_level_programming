#include <stdio.h>

/**
 * _strspn - Obtiene la longitud de una subcadena de prefijo.
 * @s: Puntero a la cadena en la que se va a buscar la subcadena de prefijo.
 * @accept: Puntero a la cadena que contiene los caracteres aceptados.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int len = 0; 
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        int match = 0;

        for (j = 0; accept[j] != '\0'; j++) {

            if (s[i] == accept[j]) {
                match = 1; 
                break;
            }
        }
	 if (match == 0) {
            break;
        }

        len++;
    }

    return len;
}
