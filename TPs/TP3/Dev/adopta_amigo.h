#ifndef __ADOPTA_AMIGO_H__
#define __ADOPTA_AMIGO_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_COLOR 50
#define MAX_VIRTUDES 10
#define MAX_DEFECTOS 10
#define MAX_DESCRIPCION 200
#define MAX_AMIGOS 50

#define ESTA_MANSION true
#define NO_ESTA_MANSION false
#define MAX_CARACTERES 2
#define PATH_AMIGOS "amigos_mansion.dat"
#define FORMATO_REQUISITOS "%[^;];%c%i;%[^;];%[^\n]\n" 
#define FORMATO_AMIGOS_ADOPTADOS "%[^;\n]\n"
#define MENOR_QUE '<'
#define MAYOR_QUE '>'
#define IGUAL_QUE '='
#define STRING_IGUALES 0
#define SIZE_READ 1

typedef struct aspecto {
	char descripcion[MAX_DESCRIPCION];
} aspecto_t;

typedef struct amigo{
	char nombre[MAX_NOMBRE];
	char color[MAX_COLOR];
	int altura;
	aspecto_t virtudes[MAX_VIRTUDES];
	int tope_virtudes;
	aspecto_t defectos[MAX_DEFECTOS];
	int tope_defectos;
	bool esta_en_mansion;
} amigo_t;

/*
 * Pre: 
 * Pos: Define el amigo a adoptar y modifica todo lo necesario.
 */
int elegir_amigo(char* archivo);

/*
 * Pre: 
 * Pos: Lista los amigos que estan actualmente en la mansion
 */
int listar_amigos(char* archivo);

/*
 * Pre: 
 * Pos: Devuelve el amigo imaginario a la mansion
 */
int devolver_amigo(char* archivo, char*nombre);

#endif /* __ADOPTA_AMIGO_H__ */
