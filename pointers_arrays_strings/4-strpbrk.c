#include <stdio.h>

char *_strpbrk(char *s, char *accept) {
  if (s == NULL || accept == NULL) {
    return NULL;
  }

  while (*s != '\0') {
    char *a = accept;
    while (*a != '\0') {
      if (*s == *a) {
        return s;
      }
      a++;
    }
    s++;
  }

  return NULL;
}
