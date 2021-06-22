#ifndef __DECISIONES_AMIGOS_H__
#define __DECISIONES_AMIGOS_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ELEGIR_AMIGO "elegir_amigo"
#define LISTAR_AMIGOS "listar_amigos"
#define DEVOLVER_AMIGO "devolver_amigo"

#define STRING_IGUAL 0
#define MAX_VECES 1

/*
* Pre:  cant_argumentos >= 0
* Pos:  Devuelve un string de alguna de las opciones que esten disponibles. 'ELEGIR_AMIGO, LISTAR_AMIGOS, DEVOLVER_AMIGO'
*/
char* decide_opcion(int cant_argumentos, char *argumentos[]);

/*
* Pre: cant_argumentos >= 0
* Pos:  Retorna la posicion de los argumentos donde esta el archivo txt.
*/
int posicion_archivo_texto(int cant_argumentos, char *argumentos[]);

/*
* Pre:  cant_argumentos >= 0
* Pos:  Retorna el string del nombre del amigo que sera devuelto.
*/
char* amigo_devuelto(int cant_argumentos, char *argumentos[]);

#endif /* __DECISIONES_AMIGOS_H__ */
