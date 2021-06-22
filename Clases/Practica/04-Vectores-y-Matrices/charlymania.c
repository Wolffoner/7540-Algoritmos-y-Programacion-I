#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPANADAS 150

const char JAMON_QUESO = 'J';
const char CARNE = 'C';
const char POLLO = 'P';
const char VERDURA = 'V';
const char HUMITA = 'H';
const char FIN = 'X';

bool es_gusto_valido(char gusto){
  return (gusto == JAMON_QUESO ||
    gusto == CARNE || 
    gusto == POLLO ||
    gusto == VERDURA ||
    gusto == HUMITA||
    gusto == FIN
  );
}

void pedir_gusto(char* gusto){
  printf("Gusto (%c,%c,%c,%c,%c) (o %c para terminar):", JAMON_QUESO, CARNE, POLLO, VERDURA, HUMITA, FIN);
  scanf(" %c", gusto);

  while(!es_gusto_valido(*gusto)){
    printf("Ese gusto no existe. Pedi bien rey (%c,%c,%c,%c,%c) (o %c para terminar):", JAMON_QUESO, CARNE, POLLO, VERDURA, HUMITA, FIN);
    scanf(" %c", gusto);
  }
}

/*
 * Pre-condiciones: 
 * - Tope mayor o igual a 0.
 * - Es un gusto valido (JAMON_QUESO, CARNE, POLLO, VERDURA o HUMITA)
 * Post-condiciones:
 * - El vector tendrá una empanada más.
 * - El tope se aumentará en 1.
 */
void cargar_gusto_de_empanada(char empanadas[MAX_EMPANADAS], int* tope, char gusto){
  
  if ((*tope) < MAX_EMPANADAS){
    empanadas[*tope] = gusto;
    (*tope)++;
  } else {
    printf("No hay lugar :(\n");
  }
}

/*
 * Pre:
 * Post: 
 * - Se devolverá el vector con empanatas hasta el tope.
 */
void cargar_empanadas(char empanadas[MAX_EMPANADAS], int* tope) {
  char gusto;
  pedir_gusto(&gusto);
  while (gusto != FIN){
    cargar_gusto_de_empanada(empanadas, tope, gusto);
    pedir_gusto(&gusto);
  }
}

void mostrar_empanadas(char empanadas[MAX_EMPANADAS], int tope){
  printf("Las empanadas pedidas son:\n");
  for(int i = 0; i < tope; i++){
    printf("%c\n", empanadas[i]);
  }
}

/*
 * Pre: gusto valido.
 * Post: devuelve la cantidad de empanadas del gusto seleccionado.
 */
int cantidad_empanadas_segun_gusto(char empanadas[MAX_EMPANADAS], int tope, char gusto){
  int contador = 0;
  for(int i = 0; i < tope; i++){
    if (empanadas[i] == gusto){
      contador++;
    }
  }
  return contador;
}


int main () {

  char empanadas[MAX_EMPANADAS];
  int tope = 0;

  cargar_empanadas(empanadas, &tope);
  mostrar_empanadas(empanadas, tope);

  int cantidad_pollo = cantidad_empanadas_segun_gusto(empanadas, tope, POLLO);
  int cantidad_carne = cantidad_empanadas_segun_gusto(empanadas, tope, CARNE);

  printf("De pollo pidieron: %i\n De carne pidieron %i", cantidad_pollo, cantidad_carne);

  return 0;
}
