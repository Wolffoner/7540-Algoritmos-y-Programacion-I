#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "escape_laboratorio.h"
#include "utiles.h"


#define NIVEL1 1
#define NIVEL2 2
#define NIVEL3 3
#define NIVEL4 4

#define CANT_BALDOSAS_PINCHE1 4
#define CANT_BALDOSAS_PINCHE2 6
#define CANT_BALDOSAS_PINCHE3 6
#define CANT_BALDOSAS_PINCHE4 10

#define CANT_GUARDIAS_ROBOT1 2
#define CANT_GUARDIAS_ROBOT2 3
#define CANT_GUARDIAS_ROBOT3 3
#define CANT_GUARDIAS_ROBOT4 4

#define CANT_BOMBAS 1
#define CANT_INTERRUPTORES 1

const bool HAY_BOMBA = true;
const bool NO_HAY_BOMBA = false;

#define MAX_DIMENSION 25
#define MAX_COORDENADAS 625

#define DIMENSION_FIL_NIVEL1 12
#define DIMENSION_COL_NIVEL1 12
#define DIMENSION_FIL_NIVEL2 17 
#define DIMENSION_COL_NIVEL2 17 
#define DIMENSION_FIL_NIVEL3 12 
#define DIMENSION_COL_NIVEL3 12
#define DIMENSION_FIL_NIVEL4 17
#define DIMENSION_COL_NIVEL4 17

#define PARED '.'
#define BALDOSAS_PINCHES 'P'
#define BOMBA 'B'
#define BALDOSA_TELETRANSPORTADORA 'T'
#define GUARDIA 'G'
#define INTERRUPTOR 'I'
#define ENTRADA 'E'
#define SALIDA 'S'
#define LLAVE 'L'
#define MONEDA 'M'
#define VACIO ' '
#define SALIDA_SIN_MOSTRAR ' '
#define LLAVE_SIN_MOSTRAR ' '

#define JOHNNY_BRAVO 'J'
#define BELLOTA 'X'
#define POLLITO 'P'
#define BLUE 'B'
#define PURO_HUESO 'H'
#define CORAJE 'C'

#define ARRIBA 'w'
#define ABAJO 's'
#define IZQUIERDA 'a'
#define DERECHA 'd'

#define CANT_MOVIMIENTOS 10
#define SIN_MOVIMIENTOS 0
#define PINCHES_ALTERA_MOV 2
#define MAX_REVIVIR 1

#define JUGANDO_NIVEL 0
#define GANO_NIVEL 1

#define JUGANDO_JUEGO 0
#define GANO_JUEGO 1
#define PERDIO_JUEGO -1


#define MAX_VECES_SALIDA 1

/*
*	Pre: numero_nivel debe ser mayor a 0 
*	Pos: asigna un valor a dimension_fil y dimension_col segun el nivel
*/
void obtener_dimensiones_nivel(int numero_nivel, int *dimension_fil, int *dimension_col){
	if(numero_nivel==NIVEL1){
		*dimension_fil=DIMENSION_FIL_NIVEL1;
		*dimension_col=DIMENSION_COL_NIVEL1;
	}
	else if(numero_nivel==NIVEL2) {
		*dimension_fil=DIMENSION_FIL_NIVEL2;
		*dimension_col=DIMENSION_COL_NIVEL2;	
	}
	else if(numero_nivel==NIVEL3) {
		*dimension_fil=DIMENSION_FIL_NIVEL3;
		*dimension_col=DIMENSION_COL_NIVEL3;	
	}
	else if(numero_nivel==NIVEL4) {
		*dimension_fil=DIMENSION_FIL_NIVEL4;
		*dimension_col=DIMENSION_COL_NIVEL4;
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0 
*	Pos: asigna un valor random a coordenada entre los valores del tope_fil y tope_col
*/
void random_coordenada(coordenada_t *coordenada, int tope_fil, int tope_col){
	coordenada->fil = rand() % tope_fil;
	coordenada->col = rand() % tope_col;
}

/*
*	Pre: pincho_fil y pincho_col deben ser mayor o igual a 0
*	Pos: retorna un bool dependiendo de si la posicion del pincho_fil y pincho_col es igual a alguna pared del nivel.
*/
bool verifica_pinches(nivel_t nivel, int pincho_fil, int pincho_col){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pincho_fil && nivel.paredes[i].col == pincho_col){
			espacio_ocupado = true;
		}
	}
	return espacio_ocupado;
}

/*
*	Pre: pincho_fil y pincho_col debe ser mayor o igual a 0
*	Pos: asigna valores contiguos al pincho_fil y pincho_col
*/
void pinchos_contiguos(nivel_t *nivel, int *pincho_fil, int *pincho_col, int i){
	int aux = 1;		
	*pincho_fil = nivel->obstaculos[i-aux].posicion.fil + aux;
	*pincho_col = nivel->obstaculos[i-aux].posicion.col;
	for (int j = i; j >= 0; j--){
		if(verifica_pinches(*nivel, *pincho_fil, *pincho_col) || (nivel->obstaculos[j].posicion.fil == *pincho_fil && nivel->obstaculos[j].posicion.col == *pincho_col)){
			*pincho_fil = nivel->obstaculos[i-aux].posicion.fil - aux;
			*pincho_col = nivel->obstaculos[i-aux].posicion.col;
			if(verifica_pinches(*nivel, *pincho_fil, *pincho_col) || (nivel->obstaculos[j].posicion.fil == *pincho_fil && nivel->obstaculos[j].posicion.col == *pincho_col)){
				*pincho_fil = nivel->obstaculos[i-aux].posicion.fil;
				*pincho_col = nivel->obstaculos[i-aux].posicion.col + aux;
				if(verifica_pinches(*nivel, *pincho_fil, *pincho_col) || (nivel->obstaculos[j].posicion.fil == *pincho_fil && nivel->obstaculos[j].posicion.col == *pincho_col)){
					*pincho_fil = nivel->obstaculos[i-aux].posicion.fil;
					*pincho_col = nivel->obstaculos[i-aux].posicion.col - aux;
				}
			}
		}
	}
}

/*
*	Pre: tope_fil y tope_col debe ser mayor a 0
*	Pos: modifica el tope_obstaculos y añade los pinches al vector obstaculos
*/
void obtener_pinches(nivel_t *nivel, int cantidad_pinches, int tope_fil, int tope_col){
	int pinche_inicial = 0;
	nivel->tope_obstaculos = nivel->tope_obstaculos + cantidad_pinches;
	for(int i = 0; i < nivel->tope_obstaculos; i++){
		nivel->obstaculos[i].tipo = BALDOSAS_PINCHES;
		if(i == pinche_inicial){
			random_coordenada(&nivel->obstaculos[i].posicion, tope_fil, tope_col);
			while(verifica_pinches(*nivel, nivel->obstaculos[i].posicion.fil, nivel->obstaculos[i].posicion.col)){
				random_coordenada(&nivel->obstaculos[i].posicion, tope_fil, tope_col);
			}
		} 
		else {
			pinchos_contiguos(nivel, &nivel->obstaculos[i].posicion.fil, &nivel->obstaculos[i].posicion.col, i);
		}
	}
}

/*
*	Pre: pos_fil y pos_col deben ser mayor o igual a 0
*	Pos: retorna un bool dependiendo si pos_fil y pos_col estan en la misma posicion que una pared o un obstaculo
*/
bool verifica_obstaculos(nivel_t nivel, int pos_fil, int pos_col, int posicion_actual){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pos_fil && nivel.paredes[i].col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < posicion_actual; i++){
		if(nivel.obstaculos[i].posicion.fil == pos_fil && nivel.obstaculos[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	return espacio_ocupado;
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_obstaculos y añade guardias al vector obstaculos
*/
void obtener_guardias(nivel_t *nivel, int cantidad_guardia, int tope_fil, int tope_col){
	int aux = nivel->tope_obstaculos;
	nivel->tope_obstaculos = nivel->tope_obstaculos + cantidad_guardia;
	for(int i = aux; i < nivel->tope_obstaculos; i++){
		nivel->obstaculos[i].tipo = GUARDIA;
		random_coordenada(&nivel->obstaculos[i].posicion, tope_fil,  tope_col);
		while(verifica_obstaculos(*nivel, nivel->obstaculos[i].posicion.fil, nivel->obstaculos[i].posicion.col, i)){
			random_coordenada(&nivel->obstaculos[i].posicion, tope_fil, tope_col);
		}
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_obstaculos y añade una bomba al vector obstaculos
*/
void obtener_bomba(nivel_t *nivel, bool hay_bomba, int tope_fil, int tope_col){
	if(hay_bomba){
		int aux = nivel->tope_obstaculos;
		int cantidad_bomba = 1;
		nivel->tope_obstaculos = nivel->tope_obstaculos + cantidad_bomba;	
		for(int i = aux; i < nivel->tope_obstaculos; i++){
			nivel->obstaculos[i].tipo = BOMBA;
			random_coordenada(&nivel->obstaculos[i].posicion, tope_fil,  tope_col);
			while(verifica_obstaculos(*nivel, nivel->obstaculos[i].posicion.fil, nivel->obstaculos[i].posicion.col, i)){
				random_coordenada(&nivel->obstaculos[i].posicion, tope_fil, tope_col);
			}
		}
	}
}

/*
*	Pre: pos_fil y pos_col deben ser mayor o igual a 0
*	Pos: verifica si pos_fil y pos_col colisionan con alguna pared, algun obstaculo o alguna herramienta
*/
bool verifica_herramientas(nivel_t nivel, int pos_fil, int pos_col, int posicion_actual){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pos_fil && nivel.paredes[i].col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_obstaculos; i++){
		if(nivel.obstaculos[i].posicion.fil == pos_fil && nivel.obstaculos[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < posicion_actual; i++){
		if(nivel.herramientas[i].posicion.fil == pos_fil && nivel.herramientas[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	return espacio_ocupado;
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_herramientas y añade teletransportadoras al vector herramientas
*/
void obtener_teletransportadoras(nivel_t *nivel, int cantidad_baldosas_tp, int tope_fil, int tope_col){
	nivel->tope_herramientas = nivel->tope_herramientas + cantidad_baldosas_tp;
	for(int i = 0; i < nivel->tope_herramientas; i++){
		nivel->herramientas[i].tipo = BALDOSA_TELETRANSPORTADORA;
		random_coordenada(&nivel->herramientas[i].posicion, tope_fil,  tope_col);
		while(verifica_herramientas(*nivel, nivel->herramientas[i].posicion.fil, nivel->herramientas[i].posicion.col, i)){
			random_coordenada(&nivel->herramientas[i].posicion, tope_fil, tope_col);
		}
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_herramientas y añade monedas al vector herramientas
*/
void obtener_monedas(nivel_t *nivel, int cantidad_baldosas_pinches, int tope_fil, int tope_col){
	int cantidad_monedas = cantidad_baldosas_pinches / 2;
	int aux = nivel->tope_herramientas;
	nivel->tope_herramientas = nivel->tope_herramientas + cantidad_monedas;
	for(int i = aux; i < nivel->tope_herramientas; i++){
		nivel->herramientas[i].tipo = MONEDA;
		random_coordenada(&nivel->herramientas[i].posicion, tope_fil,  tope_col);
		while(verifica_herramientas(*nivel, nivel->herramientas[i].posicion.fil, nivel->herramientas[i].posicion.col, i)){
			random_coordenada(&nivel->herramientas[i].posicion, tope_fil, tope_col);
		}
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_herramientas y añade llave al vector herramientas
*/
void obtener_llave(nivel_t *nivel, int tope_fil, int tope_col){
	int cantidad_llave = 1;
	int aux = nivel->tope_herramientas;
	nivel->tope_herramientas = nivel->tope_herramientas + cantidad_llave;
	for(int i = aux; i < nivel->tope_herramientas; i++){
		nivel->herramientas[i].tipo = LLAVE;
		random_coordenada(&nivel->herramientas[i].posicion, tope_fil,  tope_col);
		while(verifica_herramientas(*nivel, nivel->herramientas[i].posicion.fil, nivel->herramientas[i].posicion.col, i)){
			random_coordenada(&nivel->herramientas[i].posicion, tope_fil, tope_col);
		}
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: modifica el tope_herramientas y añade interruptor al vector herramientas
*/
void obtener_interruptor(nivel_t *nivel, bool hay_interruptor, int tope_fil, int tope_col){
	if(hay_interruptor){
		int aux = nivel->tope_herramientas;
		int cantidad_interruptor = 1;
		nivel->tope_herramientas = nivel->tope_herramientas + cantidad_interruptor;	
		for(int i = aux; i < nivel->tope_herramientas; i++){
			nivel->herramientas[i].tipo = INTERRUPTOR;
			random_coordenada(&nivel->herramientas[i].posicion, tope_fil,  tope_col);
			while(verifica_herramientas(*nivel, nivel->herramientas[i].posicion.fil, nivel->herramientas[i].posicion.col, i)){
				random_coordenada(&nivel->herramientas[i].posicion, tope_fil, tope_col);
			}
		}
	}
}

/*
*	Pre: pos_fil y pos_col deben ser mayor o igual a 0
*	Pos: retorna un bool dependiendo de si pos_fil y pos_col colisionan con alguna pared, algun obstaculo o alguna herramienta
*/
bool verifica_entrada(nivel_t nivel, int pos_fil, int pos_col){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pos_fil && nivel.paredes[i].col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_obstaculos; i++){
		if(nivel.obstaculos[i].posicion.fil == pos_fil && nivel.obstaculos[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_herramientas; i++){
		if(nivel.herramientas[i].posicion.fil == pos_fil && nivel.herramientas[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	return espacio_ocupado;
}


/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: asigna una posicion a la entrada
*/
void obtener_entrada(nivel_t *nivel, int tope_fil, int tope_col){
	random_coordenada(&nivel->entrada, tope_fil,  tope_col);
	while(verifica_entrada(*nivel, nivel->entrada.fil, nivel->entrada.col)){
		random_coordenada(&nivel->entrada, tope_fil, tope_col);
	}
}

/*
*	Pre: pos_fil y pos_col deben ser mayor o igual a 0
*	Pos: retorna un bool dependiendo de si pos_fil y pos_col colisionan con alguna pared, algun obstaculo, alguna herramienta o la entrada
*/
bool verifica_salida(nivel_t nivel, int pos_fil, int pos_col){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pos_fil && nivel.paredes[i].col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_obstaculos; i++){
		if(nivel.obstaculos[i].posicion.fil == pos_fil && nivel.obstaculos[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_herramientas; i++){
		if(nivel.herramientas[i].posicion.fil == pos_fil && nivel.herramientas[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	if(nivel.entrada.fil == pos_fil && nivel.entrada.col == pos_col){
		espacio_ocupado = true;
	}

	return espacio_ocupado;
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: asigna una posicion a la salida
*/
void obtener_salida(nivel_t *nivel, int tope_fil, int tope_col){
	random_coordenada(&nivel->salida, tope_fil,  tope_col);
	while(verifica_salida(*nivel, nivel->salida.fil, nivel->salida.col)){
		random_coordenada(&nivel->salida, tope_fil, tope_col);
	}
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: genera la matriz con posiciones vacias.
*/
void iniciar_mapa(char mapa[MAX_DIMENSION][MAX_DIMENSION], int tope_fil, int tope_col){
	for(int i=0; i < tope_fil; i++){
		for(int j=0; j < tope_col; j++){
			mapa[i][j] = VACIO;
		}
	}
}

/*
*	Pre: tope_paredes debe ser mayor o igual a 0
*	Pos: carga las paredes a la matriz.
*/
void cargar_paredes(char mapa[MAX_DIMENSION][MAX_DIMENSION], coordenada_t paredes[MAX_PAREDES], int tope_paredes){
	for (int i = 0; i < tope_paredes; i++){
		mapa[paredes[i].fil][paredes[i].col] = PARED;
	}
}

/*
*	Pre: tope_obstaculos debe ser mayor o igual a 0
*	Pos: carga los obstaculos a la matriz
*/
void cargar_obstaculos(char mapa[MAX_DIMENSION][MAX_DIMENSION], elemento_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos){
	for (int i = 0; i < tope_obstaculos; i++){
		mapa[obstaculos[i].posicion.fil][obstaculos[i].posicion.col] = obstaculos[i].tipo;
	}
}

/*
*	Pre: tope_herramientas debe ser mayor o igual a 0
*	Pos: carga las herramientas a la matriz
*/
void cargar_herramientas(char mapa[MAX_DIMENSION][MAX_DIMENSION], elemento_t herramientas[MAX_HERRAMIENTAS], int tope_herramientas){
	for (int i = 0; i < tope_herramientas; i++){
		mapa[herramientas[i].posicion.fil][herramientas[i].posicion.col] = herramientas[i].tipo;
	}
}

/*
*	Pre:
*	Pos: carga la entrada a la matriz
*/
void cargar_entrada(char mapa[MAX_DIMENSION][MAX_DIMENSION], coordenada_t entrada){
	mapa[entrada.fil][entrada.col] = ENTRADA;
}

/*
*	Pre:
*	Pos: carga el personaje a la matriz
*/
void cargar_personaje(char mapa[MAX_DIMENSION][MAX_DIMENSION], personaje_t personaje){
	mapa[personaje.posicion.fil][personaje.posicion.col] = personaje.tipo;
}

/*
*	Pre:
*	Pos: carga la salida a la matriz
*/
void cargar_salida(char mapa[MAX_DIMENSION][MAX_DIMENSION], coordenada_t salida){
	mapa[salida.fil][salida.col] = SALIDA;
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0
*	Pos: Imprime el mapa en la terminal
*/
void imprimir_mapa(char mapa[MAX_DIMENSION][MAX_DIMENSION], int tope_fil, int tope_col){
	for(int i=0; i < tope_fil; i++){
		for(int j=0; j < tope_col; j++){
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
*	Pre: 
*	Pos: retorna verdadero o falso si hay un interruptor en el vector herramientas
*/
bool verifica_interruptor(nivel_t nivel){
	bool interruptor = false;
	for (int i = 0; i < nivel.tope_herramientas; i++){
		if(nivel.herramientas[i].tipo == INTERRUPTOR){
			interruptor = true;
		}
	}
	return interruptor;
}

/*
*	Pre: 
*	Pos: verifica si hay llave en el vector herramientas y cambia el tipo de herramienta de LLAVE a LLAVE_SIN_MOSTRAR
*/
void llave_escondida(nivel_t *nivel){
	for (int i = 0; i < nivel->tope_herramientas; i++){
		if(nivel->herramientas[i].tipo == LLAVE){
			nivel->herramientas[i].tipo = LLAVE_SIN_MOSTRAR;
		}
	}
}

/*
*	Pre: 
*	Pos: verifica si hay llave_sin_mostrar en el vector herramientas y cambia el tipo de herramienta de LLAVE_SIN_MOSTRAR a LLAVE
*/
void mostrar_llave(nivel_t *nivel){
	for (int i = 0; i < nivel->tope_herramientas; i++){
		if(nivel->herramientas[i].tipo == LLAVE_SIN_MOSTRAR){
			nivel->herramientas[i].tipo = LLAVE;
		}
	}
}

/*
*	Pre: 
*	Pos: carga todas las paredes, elementos, entrada, salida y personaje al mapa.
*/
void cargar_mapa(char mapa[MAX_DIMENSION][MAX_DIMENSION], juego_t juego){
	int dimension_fil = 0;
	int dimension_col = 0;
	int nivel = juego.nivel_actual - 1;
	obtener_dimensiones_nivel(juego.nivel_actual, &dimension_fil, &dimension_col);
	iniciar_mapa(mapa, dimension_fil, dimension_col);
	cargar_paredes(mapa, juego.niveles[nivel].paredes, juego.niveles[nivel].tope_paredes);
	cargar_obstaculos(mapa, juego.niveles[nivel].obstaculos, juego.niveles[nivel].tope_obstaculos);
	cargar_herramientas(mapa, juego.niveles[nivel].herramientas, juego.niveles[nivel].tope_herramientas);
	cargar_entrada(mapa, juego.niveles[nivel].entrada);
	if (verifica_interruptor(juego.niveles[nivel]) && !juego.personaje.presiono_interruptor){
		llave_escondida(&juego.niveles[nivel]);
	}
	if(juego.personaje.presiono_interruptor){
		mostrar_llave(&juego.niveles[nivel]);
	}
	if(juego.personaje.tiene_llave){
		cargar_salida(mapa, juego.niveles[nivel].salida);
	}
	cargar_personaje(mapa, juego.personaje);
	imprimir_mapa(mapa, dimension_fil, dimension_col);
}

/*
*	Pre: 
*	Pos: verifica los poderes al chocar con obstaculos
*/
void verifica_poder_obstaculos(personaje_t *personaje, elemento_t obstaculo){
	if(obstaculo.tipo == BALDOSAS_PINCHES){
		if(personaje->tipo != POLLITO && personaje->tipo != PURO_HUESO){
			if(personaje->movimientos >= PINCHES_ALTERA_MOV){
				personaje->movimientos = personaje->movimientos - PINCHES_ALTERA_MOV;
			}
			else {
				personaje->movimientos = SIN_MOVIMIENTOS;
			}
		} 
	}
	else if(obstaculo.tipo == GUARDIA){
		if(personaje->tipo != JOHNNY_BRAVO && personaje->tipo != CORAJE){
			personaje->murio = true;
			personaje->movimientos = SIN_MOVIMIENTOS;
			personaje->posicion.fil = obstaculo.posicion.fil;
			personaje->posicion.col = obstaculo.posicion.col;
		}
	} 
	else if (obstaculo.tipo == BOMBA){
		personaje->murio = true;
		personaje->movimientos = SIN_MOVIMIENTOS;
		personaje->posicion.fil = obstaculo.posicion.fil;
		personaje->posicion.col = obstaculo.posicion.col;
	}
}

/*
*	Pre: 
*	Pos: verifica si el personaje colisiona con los obstaculos
*/
void colision_obstaculos(personaje_t *personaje, nivel_t nivel){
	for(int i = 0; i < nivel.tope_obstaculos; i++){
		if(nivel.obstaculos[i].posicion.col == personaje->posicion.col && nivel.obstaculos[i].posicion.fil == personaje->posicion.fil){
			verifica_poder_obstaculos(personaje, nivel.obstaculos[i]);
		}			
	}
}

/*
*	Pre: 
*	Pos: modifica el tope_herramientas y elimina la herramienta indicada segun la posicion
*/
void eliminar_herramienta(elemento_t herramientas[MAX_HERRAMIENTAS], int posicion, int* tope_herramientas ){
	bool esta = false;
	int i = 0;
	int pos = 0;

	while ((i < *tope_herramientas) && (!esta)){
		if(i == posicion){
			esta = true;
			pos = i;
		}
		i++;
	}
	if (esta) {
		for (i = pos; i < (*tope_herramientas-1); i++){
			herramientas[i]=herramientas[i+1];
		}
		*tope_herramientas= *tope_herramientas - 1;
	}
}

/*
*	Pre: 
*	Pos: verifica si el personaje colisiona con las herramientas
*/
void colision_herramientas(personaje_t *personaje, nivel_t *nivel){
	int aux = 1;
	int inicio_tp = 0;
	int contador_tp = 0;
	for(int i = 0; i < nivel->tope_herramientas; i++){
		if(nivel->herramientas[i].posicion.col == personaje->posicion.col && nivel->herramientas[i].posicion.fil == personaje->posicion.fil){
			if(nivel->herramientas[i].tipo == BALDOSA_TELETRANSPORTADORA && contador_tp < aux){	
				personaje->posicion.col = nivel->herramientas[i].posicion.col;
				personaje->posicion.fil = nivel->herramientas[i].posicion.col;
				if(nivel->herramientas[i+aux].tipo == BALDOSA_TELETRANSPORTADORA){
					personaje->posicion.col = nivel->herramientas[i+aux].posicion.col;
					personaje->posicion.fil = nivel->herramientas[i+aux].posicion.fil;
				} 
				else{
					personaje->posicion.col = nivel->herramientas[inicio_tp].posicion.col;
					personaje->posicion.fil = nivel->herramientas[inicio_tp].posicion.fil;
				}
				contador_tp++;	
			} 
			else if(nivel->herramientas[i].tipo == INTERRUPTOR){
				personaje->presiono_interruptor = true;
				eliminar_herramienta(nivel->herramientas, i, &nivel->tope_herramientas);
			} 
			else if (nivel->herramientas[i].tipo == LLAVE){
				personaje->tiene_llave = true;
				eliminar_herramienta(nivel->herramientas, i, &nivel->tope_herramientas);
			}
			else if ( nivel->herramientas[i].tipo == MONEDA){
				personaje->movimientos++;
				eliminar_herramienta(nivel->herramientas, i, &nivel->tope_herramientas);
			}			
		}
	}
}

/*
*	Pre: 
*	Pos: verifica si colisiona con algun elemento o pared cuando se mueve hacia arriba
*/
void colision_arriba(personaje_t *personaje, nivel_t *nivel, coordenada_t pared_prox){
	int contador_aux = 0;
	while(personaje->posicion.fil != pared_prox.fil && personaje->posicion.col == pared_prox.col && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.fil--;
		colision_obstaculos(personaje, *nivel);
		colision_herramientas(personaje, nivel);		
		if(estado_nivel(*personaje, nivel->salida)==GANO_NIVEL){
			contador_aux++;
		}
	}
	if(personaje->posicion.col == pared_prox.col && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.fil++;
	}
}

/*
*	Pre: 
*	Pos: define la pared mas proxima arriba del personaje
*/
void pared_prox_arriba(nivel_t nivel, coordenada_t *posicion, coordenada_t *pared_prox, int distancia){
	int resta = 0;
	for(int i = 0; i < nivel.tope_paredes; i++){
		resta = posicion->fil - nivel.paredes[i].fil;
		if(nivel.paredes[i].col == posicion->col && nivel.paredes[i].fil < posicion->fil && resta < distancia){
			distancia = resta;
			pared_prox->fil = nivel.paredes[i].fil;
			pared_prox->col = nivel.paredes[i].col;
		}
	}
}

/*
*	Pre: 
*	Pos: mueve el personaje hacia arriba, verifica sus colisiones hasta la pared proxima
*/
void mover_arriba(coordenada_t *posicion, juego_t *juego, int distancia_col){
	coordenada_t pared_prox;
	int nivel = juego->nivel_actual-1;
	pared_prox_arriba(juego->niveles[nivel], posicion, &pared_prox, distancia_col);
	colision_arriba(&juego->personaje, &juego->niveles[nivel], pared_prox);
}

/*
*	Pre: 
*	Pos: verifica si colisiona con algun elemento o pared cuando se mueve hacia abajo
*/
void colision_abajo(personaje_t *personaje, nivel_t *nivel, coordenada_t pared_prox){
	int contador_aux = 0;
	while(personaje->posicion.fil != pared_prox.fil && personaje->posicion.col == pared_prox.col  && contador_aux < MAX_VECES_SALIDA && !personaje->murio){
		personaje->posicion.fil++;
		colision_obstaculos(personaje, *nivel);
		colision_herramientas(personaje, nivel);		
		if(estado_nivel(*personaje, nivel->salida)==GANO_NIVEL){
			contador_aux++;
		}

	}
	if(personaje->posicion.col == pared_prox.col && contador_aux < MAX_VECES_SALIDA && !personaje->murio){
		personaje->posicion.fil--;
	}
}

/*
*	Pre: 
*	Pos: define la pared mas proxima abajo del personaje
*/
void pared_prox_abajo(nivel_t nivel, coordenada_t *posicion, coordenada_t *pared_prox, int distancia){
	int resta = 0;
	for(int i = 0; i < nivel.tope_paredes; i++){
		resta = nivel.paredes[i].fil - posicion->fil;
		if(nivel.paredes[i].col == posicion->col && nivel.paredes[i].fil > posicion->fil && resta < distancia){
			distancia = resta;
			pared_prox->fil = nivel.paredes[i].fil;
			pared_prox->col = nivel.paredes[i].col;
		}
	}
}

/*
*	Pre: 
*	Pos: mueve el personaje hacia abajo, verifica sus colisiones hasta la pared proxima
*/
void mover_abajo(coordenada_t *posicion, juego_t *juego, int distancia_col){
	coordenada_t pared_prox;
	int nivel = juego->nivel_actual-1;
	pared_prox_abajo(juego->niveles[nivel], posicion, &pared_prox, distancia_col);
	colision_abajo(&juego->personaje, &juego->niveles[nivel], pared_prox);
}

/*
*	Pre: 
*	Pos: verifica si colisiona con algun elemento o pared cuando se mueve hacia la derecha
*/
void colision_derecha(personaje_t *personaje, nivel_t *nivel, coordenada_t pared_prox){
	int contador_aux = 0;
	while(personaje->posicion.col != pared_prox.col && personaje->posicion.fil == pared_prox.fil && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.col++;
		colision_obstaculos(personaje, *nivel);
		colision_herramientas(personaje, nivel);		
		if(estado_nivel(*personaje, nivel->salida)==GANO_NIVEL){
			contador_aux++;
		}
	}
	if(personaje->posicion.fil == pared_prox.fil && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.col--;
	}
}

/*
*	Pre: 
*	Pos: define la pared mas proxima a la derecha del personaje
*/
void pared_prox_derecha(nivel_t nivel, coordenada_t *posicion, coordenada_t *pared_prox, int distancia){
	int resta = 0;
	for(int i = 0; i < nivel.tope_paredes; i++){
		resta = nivel.paredes[i].col - posicion->col;
		if(nivel.paredes[i].fil == posicion->fil && nivel.paredes[i].col > posicion->col && resta < distancia){
			distancia = resta;
			pared_prox->fil = nivel.paredes[i].fil;
			pared_prox->col = nivel.paredes[i].col;
		}
	}
}

/*
*	Pre: 
*	Pos: mueve el personaje hacia la derecha, verifica sus colisiones hasta la pared proxima
*/
void mover_derecha(coordenada_t *posicion, juego_t *juego, int distancia_fil){
	coordenada_t pared_prox;
	int nivel = juego->nivel_actual-1;
	pared_prox_derecha(juego->niveles[nivel], posicion, &pared_prox, distancia_fil);
	colision_derecha(&juego->personaje, &juego->niveles[nivel], pared_prox);
}

/*
*	Pre: 
*	Pos: verifica si colisiona con algun elemento o pared cuando se mueve hacia la izquierda
*/
void colision_izquierda(personaje_t *personaje, nivel_t *nivel, coordenada_t pared_prox){
	int contador_aux = 0;
	while(personaje->posicion.col != pared_prox.col && personaje->posicion.fil == pared_prox.fil && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.col--;
		colision_obstaculos(personaje, *nivel);
		colision_herramientas(personaje, nivel);	
		if(estado_nivel(*personaje, nivel->salida)== GANO_NIVEL){
			contador_aux++;
		}
	}
	if(personaje->posicion.fil == pared_prox.fil && contador_aux < MAX_VECES_SALIDA){
		personaje->posicion.col++;
	}
}

/*
*	Pre: 
*	Pos: define la pared mas proxima a la izquierda del personaje
*/
void pared_prox_izquierda(nivel_t nivel, coordenada_t *posicion, coordenada_t *pared_prox, int distancia){
	int resta = 0;
	for(int i = 0; i < nivel.tope_paredes; i++){
		resta = posicion->col - nivel.paredes[i].col;
		if(nivel.paredes[i].fil == posicion->fil && nivel.paredes[i].col < posicion->col && resta < distancia){
			distancia = resta;
			pared_prox->fil = nivel.paredes[i].fil;
			pared_prox->col = nivel.paredes[i].col;
		}
	}
}

/*
*	Pre: 
*	Pos: mueve el personaje hacia la izquierda, verifica sus colisiones hasta la pared proxima
*/
void mover_izquierda(coordenada_t *posicion, juego_t *juego, int distancia_fil){
	coordenada_t pared_prox;
	int nivel = juego->nivel_actual-1;
	pared_prox_izquierda(juego->niveles[nivel], posicion, &pared_prox, distancia_fil);
	colision_izquierda(&juego->personaje, &juego->niveles[nivel], pared_prox);
}

/*
*	Pre: pos_fil y pos_col deben ser mayor a 0 
*	Pos: retorna verdadero o falso si colisiona con alguna pared, elemento, entrada o salida
*/
bool verifica_posicion_libre(nivel_t nivel, int pos_fil, int pos_col){
	bool espacio_ocupado = false;
	for(int i = 0; i < nivel.tope_paredes; i++){
		if(nivel.paredes[i].fil == pos_fil && nivel.paredes[i].col == pos_col){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_obstaculos; i++){
		if(nivel.obstaculos[i].posicion.fil == pos_fil && nivel.obstaculos[i].posicion.col == pos_col && nivel.obstaculos[i].tipo != GUARDIA){
			espacio_ocupado = true;
		}
	}
	for(int i = 0; i < nivel.tope_herramientas; i++){
		if(nivel.herramientas[i].posicion.fil == pos_fil && nivel.herramientas[i].posicion.col == pos_col){
			espacio_ocupado = true;
		}
	}
	if(nivel.entrada.fil == pos_fil && nivel.entrada.col == pos_col){
			espacio_ocupado = true;
	}
	if(nivel.salida.fil == pos_fil && nivel.salida.col == pos_col){
			espacio_ocupado = true;
	}
	return espacio_ocupado;
}

/*
*	Pre: tope_fil y tope_col deben ser mayor a 0 
*	Pos: Mueve los guardias en posiciones aleatorias
*/
void mover_guardias(juego_t* juego, int tope_fil, int tope_col){
	int nivel = juego->nivel_actual-1;
	for(int i = 0; i < juego->niveles[nivel].tope_obstaculos; i++){
		if(juego->niveles[nivel].obstaculos[i].tipo == GUARDIA){
			random_coordenada(&juego->niveles[nivel].obstaculos[i].posicion, tope_fil,  tope_col);
			while(verifica_posicion_libre(juego->niveles[nivel], juego->niveles[nivel].obstaculos[i].posicion.fil, juego->niveles[nivel].obstaculos[i].posicion.col)){
				random_coordenada(&juego->niveles[nivel].obstaculos[i].posicion, tope_fil, tope_col);
			}
		}
	}
}

/*
*	Pre: 
*	Pos: Retorna verdadero o falso si hallo la salida y si el personaje posee la llave
*/
bool hallo_salida(personaje_t personaje, coordenada_t salida){
	return ((personaje.posicion.fil == salida.fil && personaje.posicion.col == salida.col) && personaje.tiene_llave);
}
/*
*	Pre: 
*	Pos: Inicializa el personaje en el juego
*/
void inicializar_personaje(juego_t* juego, char tipo_personaje){
	int nivel = juego->nivel_actual-1;
	juego->personaje.tipo = tipo_personaje; 
	juego->personaje.tiene_llave = false; 
	juego->personaje.presiono_interruptor = false; 
	juego->personaje.movimientos = CANT_MOVIMIENTOS;
	juego->personaje.murio = false;
	juego->personaje.posicion.fil = juego->niveles[nivel].entrada.fil;
	juego->personaje.posicion.col = juego->niveles[nivel].entrada.col;
}

int estado_juego(juego_t juego){
	int estado = JUGANDO_JUEGO;
	int nivel = juego.nivel_actual - 1;
	if (juego.nivel_actual == NIVEL4){
		if(hallo_salida(juego.personaje, juego.niveles[nivel].salida) && juego.personaje.movimientos > SIN_MOVIMIENTOS && 
		(!juego.personaje.murio || (juego.personaje.murio && (juego.personaje.tipo == BELLOTA || juego.personaje.tipo == BLUE)))){
			estado = GANO_JUEGO;
		} else if ( juego.personaje.movimientos <= SIN_MOVIMIENTOS || juego.personaje.murio){
			estado = PERDIO_JUEGO;
		}
	} 
	if (juego.personaje.murio || juego.personaje.movimientos <= SIN_MOVIMIENTOS){
		estado = PERDIO_JUEGO;
	}

	if ((juego.personaje.tipo == BELLOTA || juego.personaje.tipo == BLUE) && juego.personaje.murio && juego.personaje.movimientos > SIN_MOVIMIENTOS){
		estado = JUGANDO_JUEGO;
	}
	return estado;
}

void inicializar_juego(juego_t* juego, char tipo_personaje){
	juego->nivel_actual = NIVEL1;
	inicializar_nivel(&juego->niveles[0], NIVEL1, CANT_BALDOSAS_PINCHE1, CANT_GUARDIAS_ROBOT1, NO_HAY_BOMBA);
	inicializar_nivel(&juego->niveles[1], NIVEL2, CANT_BALDOSAS_PINCHE2, CANT_GUARDIAS_ROBOT2, NO_HAY_BOMBA);
	inicializar_nivel(&juego->niveles[2], NIVEL3, CANT_BALDOSAS_PINCHE3, CANT_GUARDIAS_ROBOT3, HAY_BOMBA);
	inicializar_nivel(&juego->niveles[3], NIVEL4, CANT_BALDOSAS_PINCHE4, CANT_GUARDIAS_ROBOT4, HAY_BOMBA);
	inicializar_personaje(juego, tipo_personaje);
}

int estado_nivel(personaje_t personaje, coordenada_t salida){
	int estado_nivel = JUGANDO_NIVEL;
	if(hallo_salida(personaje, salida)){
		estado_nivel = GANO_NIVEL;
	}
	return estado_nivel;
}

void inicializar_nivel(nivel_t* nivel, int numero_nivel, int cantidad_baldosas_pinches, int cantidad_guardia, bool hay_bomba){
	bool hay_interruptor = hay_bomba;
	int dimension_fil = 0;
	int dimension_col = 0;
	nivel->tope_obstaculos = 0;
	nivel->tope_herramientas = 0;
	obtener_dimensiones_nivel(numero_nivel, &dimension_fil, &dimension_col);
	obtener_paredes(numero_nivel, nivel->paredes, &nivel->tope_paredes);
	obtener_pinches(nivel, cantidad_baldosas_pinches, dimension_fil, dimension_col);
	obtener_guardias(nivel, cantidad_guardia, dimension_fil, dimension_col);
	obtener_bomba(nivel, hay_bomba, dimension_fil, dimension_col);
	obtener_teletransportadoras(nivel, cantidad_guardia, dimension_fil, dimension_col);
	obtener_monedas(nivel, cantidad_baldosas_pinches, dimension_fil, dimension_col);
	obtener_llave(nivel, dimension_fil, dimension_col);
	obtener_interruptor(nivel, hay_interruptor, dimension_fil, dimension_col);
	obtener_entrada(nivel, dimension_fil, dimension_col);
	obtener_salida(nivel, dimension_fil, dimension_col);
}

void mover_personaje(juego_t* juego, char movimiento){
	int dimension_fil = 0;
	int dimension_col = 0;
	obtener_dimensiones_nivel(juego->nivel_actual, &dimension_fil, &dimension_col);
	if(movimiento == ARRIBA){	
		mover_arriba(&juego->personaje.posicion, juego, dimension_col);
	} 
	else if (movimiento == ABAJO){
		mover_abajo(&juego->personaje.posicion, juego, dimension_col);
	}
	else if (movimiento == DERECHA){
		mover_derecha(&juego->personaje.posicion, juego, dimension_fil);
	} 
	else if (movimiento == IZQUIERDA){
		mover_izquierda(&juego->personaje.posicion, juego, dimension_fil);
	} 
	else {
		printf("Introdujiste un caracter distinto\n");
		juego->personaje.movimientos++;
	}
	if(juego->personaje.movimientos > SIN_MOVIMIENTOS){
		juego->personaje.movimientos--;
	} else if(juego->personaje.movimientos == SIN_MOVIMIENTOS){
		juego->personaje.murio = true;
	}
	mover_guardias(juego, dimension_fil, dimension_col);
}

void mostrar_juego(juego_t juego){
	char mapa[MAX_DIMENSION][MAX_DIMENSION];
	cargar_mapa(mapa, juego);
}