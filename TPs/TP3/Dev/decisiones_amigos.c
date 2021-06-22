#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "decisiones_amigos.h"

/*
* Pre: 
* Pos:  Verifica que el string de una secunecia '.txt' y retorna el resultado.
*/
int verifica_archivo_texto(char* argumento){
	bool resultado = false;
	size_t tamanio_argumento = strlen(argumento);
	for(int i = 0; i < tamanio_argumento; i ++){
		if(argumento[i] == '.' && argumento[i+1] == 't' && argumento[i+2] == 'x' && argumento[i+3] == 't'){
		resultado = true;
		}
	}
	return resultado;
}

char* decide_opcion(int cant_argumentos, char *argumentos[]){
	int contador = 0;
	char* resultado = "";
	for(int i = 0; i < cant_argumentos; i++){
		if(strcmp(argumentos[i], ELEGIR_AMIGO) == STRING_IGUAL && contador < MAX_VECES){
			resultado = ELEGIR_AMIGO;
			contador++;
		} else if (strcmp(argumentos[i], LISTAR_AMIGOS) == STRING_IGUAL && contador < MAX_VECES){
			resultado = LISTAR_AMIGOS;
			contador++;
		} else if (strcmp(argumentos[i], DEVOLVER_AMIGO) == STRING_IGUAL && contador < MAX_VECES){
			resultado = DEVOLVER_AMIGO;
			contador++;
		}
	}
	return resultado;
}

char* amigo_devuelto(int cant_argumentos, char *argumentos[]){
	int contador = 0;
	char* resultado = "";
	for(int i = 0; i < cant_argumentos; i++){
		if(strcmp(argumentos[i], DEVOLVER_AMIGO) == STRING_IGUAL && contador < MAX_VECES){
			resultado = argumentos[i+1];
			contador++;
		}
	}
	return resultado;
}

int posicion_archivo_texto(int cant_argumentos, char *argumentos[]){
	int posicion = 0;
	int contador = 0;
	for(int i = 0; i < cant_argumentos; i++){
		if (verifica_archivo_texto(argumentos[i]) && contador < MAX_VECES){
			posicion = i;
			contador++;
		}
	}
	return posicion;
}

