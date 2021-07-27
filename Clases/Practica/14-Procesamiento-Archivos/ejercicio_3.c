#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

typedef struct colab {
	char nombre[MAX_NOMBRE];
	int goles_metidos;
	int goles_errados;
	int faltas_cometidas;
	int cantidad_lesiones;
} colab_t;

int main(int argc, char* argv[]){

	FILE* colabs = fopen(argv[1], "r+");
	// --> Chequear si se abrio bien!!
	colab_t colab;

	int cantidad_minima_de_goles = atoi(argv[2]);

	printf("cantidad: %i\n", cantidad_minima_de_goles);

	int leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	
	while (leidos_colabs == 1){
		if (colab.goles_metidos > cantidad_minima_de_goles) {
			printf("%s - %i - %i - %i - %i\n", colab.nombre, colab.goles_metidos, colab.goles_errados, colab.faltas_cometidas, colab.cantidad_lesiones);
		}
		leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	}

	fclose(colabs);
	

	return 0;
}
