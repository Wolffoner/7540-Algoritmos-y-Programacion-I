#include <stdio.h>
#include "panikeso.h"

int main(){

	juego_t jueguito;

	inicializar_juego(&jueguito);

	while (jueguito.distancia > 0){
		jugar_turno(&jueguito);
	}

	printf("Ganó: %c\n", jueguito.ultima_jugada);

	return 0;
}