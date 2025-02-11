#include <string.h>


/*
 * _memset - Llena un bloque de memoria con un valor constante.
 * @s: Puntero al inicio del bloque de memoria.
 * @b: Valor constante a establecer en cada byte.
 * @n: Número de bytes a rellenar.
 *
 * Descripción:
 * Esta función itera sobre un bloque de memoria de 'n' bytes, 
 * comenzando en la dirección apuntada por 's', y establece cada byte 
 * a el valor proporcionado por 'b'.
 *
 * Retorno:
 * Retorna un puntero a la misma área de memoria 's', ahora modificada.
 */
char *_memset(char *s, char b, unsigned int n) {
  unsigned int i;

  for (i = 0; i < n; i++) {
    s[i] = b;
  }

  return s;
}
