#include <stdio.h>
#include <strings.h>
#include "escondidas.h"

#define MAX_NOMBRE 50
#define MAX_COLABS 23



void cargar_vector(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs){
	strcpy(colabs[0].nombre,"Manu");
	colabs[0].fil = 3;
	colabs[0].col = 5;

	strcpy(colabs[1].nombre,"Charly");
	colabs[1].fil = 5;
	colabs[1].col = 3;

	strcpy(colabs[2].nombre,"Sol");
	colabs[2].fil = 2;
	colabs[2].col = 7;

	strcpy(colabs[3].nombre,"Nico");
	colabs[3].fil = 5;
	colabs[3].col = 1;
	
	strcpy(colabs[4].nombre,"Delfi");
	colabs[4].fil = 7;
	colabs[4].col = 1;
	
	strcpy(colabs[5].nombre,"Rena");
	colabs[5].fil = 6;
	colabs[5].col = 8;
	
	strcpy(colabs[6].nombre,"Agus");
	colabs[6].fil = 0;
	colabs[6].col = 0;
	
	strcpy(colabs[7].nombre,"Juli");
	colabs[7].fil = 3;
	colabs[7].col = 8;
	
	strcpy(colabs[8].nombre, "Santi");
	colabs[8].fil = 7;
	colabs[8].col = 4;
	
	strcpy(colabs[9].nombre,"Rosi");
	colabs[9].fil = 1;
	colabs[9].col = 1;
	
	strcpy(colabs[10].nombre, "Mariano");
	colabs[10].fil = 4;
	colabs[10].col = 6;
	
	strcpy(colabs[11].nombre, "Eze");
	colabs[11].fil = 9;
	colabs[11].col = 1;
	
	strcpy(colabs[12].nombre, "Cande");
	colabs[12].fil = 8;
	colabs[12].col = 8;
	
	strcpy(colabs[13].nombre, "Franco");
	colabs[13].fil = 4;
	colabs[13].col = 9;
	
	strcpy(colabs[14].nombre, "Meli");
	colabs[14].fil = 2;
	colabs[14].col = 3;

	strcpy(colabs[15].nombre, "Stephy");
	colabs[15].fil = 8;
	colabs[15].col = 2;

	(*cantidad_colabs) = 16;
}

//
//Post: devuelve -1 si no encontro el colab o la posicion en la que esta
int buscar_colab(colaborador_t colabs[MAX_COLABS], int cantidad_colabs, char nombre_buscado[MAX_NOMBRE]){
	int posicion = -1;
	/*for(int i = 0; i< cantidad_colabs;i++){
		if(strcmp(colabs[i].nombre, nombre_buscado) == 0){
			posicion = i;
		}
	}
	return posicion;
	*/
	int i = 0;
	while(i<cantidad_colabs && posicion == -1){
		if(strcmp(colabs[i].nombre, nombre_buscado) == 0){
			posicion = i;
		}
		i++;
	}
	return posicion;
}

void imprimir_posicion(colaborador_t colabs[MAX_COLABS], int cantidad_colabs, char nombre_buscado[MAX_NOMBRE]){
	int posicion = buscar_colab(colabs, cantidad_colabs, nombre_buscado);
	if(posicion != -1){
		printf("%s esta en la fila %i y en la columna %i",nombre_buscado,colabs[posicion].fil, colabs[posicion].col);
	}else{
		printf("El colaborador %s se escapa de mi vida", nombre_buscado);
	}
}
