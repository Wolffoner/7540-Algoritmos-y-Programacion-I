#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "escape_laboratorio.h"
#include "detector_personajes.h"

#define NIVEL4 4

#define CANT_VIDAS 1
#define CANT_MOVIMIENTOS 10
#define SIN_MOVIMIENTOS 0

#define JUGANDO_NIVEL 0 
#define GANO_NIVEL 1

#define JUGANDO_JUEGO 0
#define GANO_JUEGO 1
#define PERDIO_JUEGO -1

/*
*	Pre:
*	Pos: Pregunta hacia donde mover el personaje 
*/
void pregunta_movimiento(char *movimiento){
	printf("Hacia donde te quieres mover? (w [Arriba], a [Izquierda], s [Abajo], d [Derecha])\n");
	scanf(" %c", movimiento);
}

/*
*	Pre:
*	Pos: Verifica si el personaje revive
*/
void verifica_revive(juego_t* juego, int* revivio){
	if(juego->personaje.murio && (juego->personaje.tipo == BELLOTA || juego->personaje.tipo == BLUE) && *revivio < CANT_VIDAS){
		juego->personaje.movimientos = CANT_MOVIMIENTOS;
		*revivio= *revivio + CANT_VIDAS;
	}
}

/*
*	Pre:
*	Pos: cambia los parametros del personaje al pasar de nivel
*/
void paso_nivel(juego_t* juego, int* nivel){
	juego->nivel_actual++;
	*nivel = juego->nivel_actual - 1;
	juego->personaje.tiene_llave = false;
	juego->personaje.presiono_interruptor = false;
	juego->personaje.movimientos = juego->personaje.movimientos + CANT_MOVIMIENTOS;
	juego->personaje.posicion.fil = juego->niveles[*nivel].entrada.fil;
	juego->personaje.posicion.col = juego->niveles[*nivel].entrada.col;
}

/*
*	Pre:
*	Pos: retorna un bool dependiendo de si el personaje murio y se quedo sin movimientos
*/
bool estado_personaje(personaje_t personaje){
	bool estado = true;
	if (personaje.movimientos <= SIN_MOVIMIENTOS && personaje.murio){
		estado = false;
	}
	return estado;
}

int main(){
	srand((unsigned)time(NULL));
	juego_t juego;
	char movimiento = ' ';
	int nivel = 0;
	int revivio = 0;
	detectar_personaje(&juego.personaje.tipo);
	system("clear");
	inicializar_juego(&juego, juego.personaje.tipo);	
	while(estado_juego(juego) == JUGANDO_JUEGO){
		while(estado_nivel(juego.personaje, juego.niveles[nivel].salida) == JUGANDO_NIVEL && estado_personaje(juego.personaje)){
			mostrar_juego(juego);
			pregunta_movimiento(&movimiento);
			mover_personaje(&juego, movimiento);
			verifica_revive(&juego, &revivio);
			system("clear");
		}
		if(estado_nivel(juego.personaje, juego.niveles[nivel].salida) == GANO_NIVEL && juego.nivel_actual < NIVEL4){
			paso_nivel(&juego, &nivel);
		}
	}
	if(estado_juego(juego) == PERDIO_JUEGO){
		printf("Perdiste el juego\n");
	}
	
	if(estado_juego(juego) == GANO_JUEGO){
		printf("Ganaste el juego\n");
	}

	return 0;
}
