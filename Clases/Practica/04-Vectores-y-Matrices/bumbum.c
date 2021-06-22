#include <stdio.h>
#include <stdbool.h>

#define ALTO 4
#define ANCHO 4

const char AWITA = 'A';
const char BARQUITO = 'B';
const char TOCADO = 'T';
const char ERRADO = 'X';

/*
 * Pre: - 
 * Post: Devuelve el terreno lleno de AWITA
 */
void llenar_con_agua(char terreno[ALTO][ANCHO]){
  for (int i = 0; i < ALTO; i++) {
    for (int j = 0; j < ANCHO; j++) {
      terreno[i][j] = AWITA;
    }
  }
}

void posicionar_barquito(char terreno[ALTO][ANCHO]){
  
  /*
  terreno -> matriz
  terreno[1] -> vector
  terreno[1][2] -> caracter
  */
  // quiero poner barquito en la 1 1
  terreno[1][1] = BARQUITO;
  // quiero poner barquito en la 1 2
  terreno[1][2] = BARQUITO;

  /* 
   * Pedirle al usuario la fila.
   * Chequear que esta dentro de los limites.
   * Pedirle la columna.
   * Chequear que esta dentro de los limites.
   */
}

void mostrar_terreno(char terreno[ALTO][ANCHO]){
  for (int i = 0; i < ALTO; i++) {
    for (int j = 0; j < ANCHO; j++) {
      printf("%c", terreno[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void disparar(char terreno[ALTO][ANCHO], int fila, int columna){
  if (terreno[fila][columna] == BARQUITO){
    terreno[fila][columna] = TOCADO;
  } else if (terreno[fila][columna] == AWITA){
    terreno[fila][columna] = ERRADO;
  }
}

int main () {

  char terreno[ALTO][ANCHO];
  llenar_con_agua(terreno);
  posicionar_barquito(terreno);
  mostrar_terreno(terreno);

  int fila, columna;
  printf("Fila disparo: ");
  scanf("%i", &fila);
  printf("Columna disparo: ");
  scanf("%i", &columna);

  disparar(terreno, fila, columna);
  mostrar_terreno(terreno);

  return 0;
}
