#ifndef __DETECTOR_PERSONAJES_H__
#define __DETECTOR_PERSONAJES_H__

// Fecha de nacimiento Maxima y Minima.
#define MIN_FECHA 1988
#define MAX_FECHA 2008

// Preferencias de sabor.
#define DULCE 'D'
#define SALADO 'S'
#define AMARGO 'A'

// Tallas de Zapatos Maxima, Minima o sin zapatos.
#define SIN_ZAPATOS 0
#define MIN_TALLA_ZAPATOS 33
#define MAX_TALLA_ZAPATOS 47
// Rangos de talla para multiplicarlos
#define MAX_RANGO_TALLA1 37
#define MAX_RANGO_TALLA2 42

// Color preferido.
#define AZUL 'A'
#define AMARILLO 'Y'
#define VERDE 'V'
#define NEGRO 'N'
#define BLANCO 'B'
#define ROSA 'R'

// Altura Maxima y Minima.
#define MIN_ALTURA 10
#define MAX_ALTURA 250

// Puntos Obtenidos
#define MIN_PUNTOS 5
#define MED_PUNTOS 15
#define MAX_PUNTOS 20

//Multiplicadores de puntos
#define MULTIPLICADOR_1 1
#define MULTIPLICADOR_2 2
#define MULTIPLICADOR_3 3
#define MULTIPLICADOR_4 4

// Numero Divisible para sacar el resto (%)
#define NUMERO_DIV 20

// Alturas Predeterminadas
#define ALTURA_JOHNNY_BRAVO 180 
#define ALTURA_BELLOTA 120
#define ALTURA_POLLITO 50
#define ALTURA_BLUE 140
#define ALTURA_PURO_HUESO 200
#define ALTURA_CORAJE 30

// Nombres Personajes
#define JOHNNY_BRAVO 'J'
#define BELLOTA 'X'
#define POLLITO 'P'
#define BLUE 'B'
#define PURO_HUESO 'H'
#define CORAJE 'C'

// Rangos de los personajes
#define MIN_RANGO_PERSONAJE1 1
#define MAX_RANGO_PERSONAJE1 80
#define MAX_RANGO_PERSONAJE2 160
#define MAX_RANGO_PERSONAJE3 240

/*
 * Pre:
 * Post: Define un personaje segun las especificaciones que hemos hecho acerca del personaje.
 */
void detectar_personaje(char* personaje_detectado);

#endif /*  __DETECTOR_PERSONAJES_H__ */
