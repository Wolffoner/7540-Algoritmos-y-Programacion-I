#include <stdio.h>
#include "escondidas.h"
#include <string.h>

int main(){
	
	colaborador_t colabs[MAX_COLABS];
	int cantidad_colabs = 0;

	cargar_vector(colabs,&cantidad_colabs);


	for(int i=0; i<cantidad_colabs;i++){
		printf("%s\tFila:%i\tColumna:%i\n",colabs[i].nombre, colabs[i].fil, colabs[i].col);
	}

	char nombre_buscado[MAX_NOMBRE];
	strcpy(nombre_buscado,"Berni");

	//buscar_colab(colabs,cantidad_colabs,nombre_buscado);
	imprimir_posicion(colabs,cantidad_colabs,nombre_buscado);



	return 0;
}