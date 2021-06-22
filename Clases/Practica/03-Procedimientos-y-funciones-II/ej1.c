#include <stdio.h>
#include <stdbool.h>

const int DESFASAJE_MAYUS_MINUS = 32;

/*
 * Tarea: escribir pre/post.
 */
bool es_minuscula(char letra) {
  // Tarea: usar constantes.
  return ((letra) >= 'a' && (letra) <= 'z');
}

/*
 * PRE: -
 * POST: modifica el parametro letra a mayuscula, solo si es minuscula.
 *       imprime por pantalla la letra modificada junto con un mensaje.
 */
void capitalizar(char* letra) {
  if(es_minuscula(*letra)) {
    (*letra) = (*letra) - DESFASAJE_MAYUS_MINUS;
  }
  printf("Dentro de la función %c\n", *letra);
}

int main () {
  char letra = 'A';

  printf("Letra inicial %c\n", letra);

  capitalizar(&letra);

  printf("Letra final %c\n", letra);

  return 0;
}
