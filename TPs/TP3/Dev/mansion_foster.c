#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "decisiones_amigos.h"
#include "adopta_amigo.h"

int main(int argc, char *argv[]){
	char* decision = decide_opcion(argc, argv);
	int posicion_lista_amigos = posicion_archivo_texto(argc, argv);
	char* amigo_a_devolver = amigo_devuelto(argc, argv);

	if (strcmp(decision, ELEGIR_AMIGO) == 0){
		if(elegir_amigo(argv[posicion_lista_amigos]) == 1){
			printf("Se adopto un amigo\n");
		} else {
			printf("No se pudo adoptar ningun amigo\n");
		}
	} 
	else if(strcmp(decision, LISTAR_AMIGOS) == 0){
		if(listar_amigos(PATH_AMIGOS) != 1){
			printf("No se pudo mostrar la lista\n");
		}
	} 
	else if(strcmp(decision, DEVOLVER_AMIGO) == 0){
		if(devolver_amigo(PATH_AMIGOS, amigo_a_devolver) == 1){
			printf("Se devolvio amigo con exito\n");
		} else {
			printf("No se pudo devolver el amigo\n");
		}
	} 
	else{
		printf("Vuelve a introducir un comando\n");
	}
	return 0;
}
