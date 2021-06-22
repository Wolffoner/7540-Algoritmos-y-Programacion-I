#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_NOMBRE 50
#define MAX_COLABS 23

typedef struct colaborador{
	char nombre[MAX_NOMBRE];
	int fil;
	int col;
}colaborador_t;

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

/*
 * Pre: Tope mayor a 0. Posicion valida del vector.
 * Post: Se borrará el colab del vector, se reduce el tope en 1.
 */
void eliminar_colab(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs, int posicion){
	// colabs[posicion] = colabs[(*cantidad_colabs) - 1];
	strcpy(colabs[posicion].nombre, colabs[(*cantidad_colabs) - 1].nombre);
	colabs[posicion].fil = colabs[(*cantidad_colabs) - 1].fil;
	colabs[posicion].col = colabs[(*cantidad_colabs) - 1].col;
	(*cantidad_colabs)--;
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

void mostrar_habitacion(colaborador_t colabs[MAX_COLABS], int cantidad_colabs){

	/* Inicializar la matriz */
	char habitacion[10][10];

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			habitacion[i][j] = '_';
		}
	}

	/* Cargar las cosas a mostrar */
	for(int i = 0; i < cantidad_colabs; i++){
		/* que teno que aser */
		char inicial = colabs[i].nombre[0];
		habitacion[colabs[i].fil][colabs[i].col] = inicial;
	}


	/* Mostrar por pantalla */
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(int i = 0; i < 10; i++){
		printf("%i ", i);
		for(int j = 0; j < 10; j++){
			printf("%c ", habitacion[i][j]);
		}
		printf("\n");
	}
}

int main(){

	colaborador_t colabs[MAX_COLABS];
	int cantidad_colabs = 0;

	cargar_vector(colabs,&cantidad_colabs);
	// for(int i=0; i<cantidad_colabs;i++){
	// 	printf("%s\tFila:%i\tColumna:%i\n",colabs[i].nombre, colabs[i].fil, colabs[i].col);
	// }

	mostrar_habitacion(colabs, cantidad_colabs);

	/*
	srand( (unsigned int) time(NULL));

	for (int i = 0; i < 1000000000; i++){
		int numero_aleatorio = rand()%50;
		printf("%i %i\n", (unsigned int) time(NULL), numero_aleatorio);
	}

	*/
	return 0;
}