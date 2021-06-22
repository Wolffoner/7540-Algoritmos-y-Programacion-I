#ifndef __PANIKESO_H__
#define __PANIKESO_H__

#include <stdbool.h>

/*
typedef struct jugador {
	int pie;
	char inicial;
} jugador_t

typedef struct juego {
	int distancia;
	jugador_t pan;
	juagdor_t queso;
} juego_t;
*/

typedef struct juego {
	int distancia;
	int pan_pie;
	char pan_inicial;
	int queso_pie;
	char queso_inicial;
	char ultima_jugada;
} juego_t;

/*
 * Pre y post
 */
void inicializar_juego(juego_t* juego);

/*
 * Pre y post
 */
void jugar_turno(juego_t* juego);

bool gano_pan(juego_t juego);

#endif /* __PANIKESO_H__ */