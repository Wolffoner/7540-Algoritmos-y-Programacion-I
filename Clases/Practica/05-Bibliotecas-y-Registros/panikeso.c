#include <stdio.h>
#include "panikeso.h"

const int DISTANCIA_INICIAL = 200;

void inicializar_juego(juego_t* juego){

	(*juego).distancia = DISTANCIA_INICIAL;
	// juego->distancia = DISTANCIA_INICIAL;

	printf("Pan, decime el largo de tu pie: ");
	scanf("%i", &((*juego).pan_pie));

	printf("Pan, decime el largo de tu pie: ");
	scanf(" %c", &((*juego).pan_inicial));

	printf("Queso, decime el largo de tu pie: ");
	scanf("%i", &((*juego).queso_pie));

	printf("Queso, decime el largo de tu pie: ");
	scanf(" %c", &((*juego).queso_inicial));
}

/*
 * pre y post
 */
void jugar_turno(juego_t* juego){

	(*juego).distancia -= (*juego).pan_pie;
	(*juego).ultima_jugada = (*juego).pan_inicial;

	if ((*juego).distancia > 0) {
		(*juego).distancia = (*juego).distancia - (*juego).queso_pie;
		(*juego).ultima_jugada = (*juego).queso_inicial;
	}
}

/*
 * ESTO NO TIENE SENTIDO, ES SOLO UN EJEMPLO
 */
bool gano_pan(juego_t juego){
	return true;
}