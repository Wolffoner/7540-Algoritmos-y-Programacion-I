#include <stdio.h>
#include <stdbool.h>

#define MAX_NOMBRE 25
typedef struct pelicula{
	char nombre[MAX_NOMBRE];
	short anio;
	bool pasa_bechdel_test;
	char opinion; //B: bueno, R: regular, M: malo
}pelicula_t;

void imprimir_pelicula(pelicula_t pelicula){
	printf("-------\n");
	printf("Nombre: %s\n", pelicula.nombre);
	printf("Año: %hi\n", pelicula.anio);
	if (pelicula.pasa_bechdel_test){
		printf("Pasa el test de Bechdel? Si\n");
	} else {
		printf("Pasa el test de Bechdel? No\n");
	}
	printf ("Opinion: %c\n", pelicula.opinion);
	printf("-------\n");
}

int main(){

	FILE* resenias = fopen("reseñas.dat", "r");
	if (resenias == NULL){
		printf("No se puede abrir el archivo\n");
		return -1;
	}

	pelicula_t pelicula;
	int leidos = fread(&pelicula, sizeof(pelicula_t), 1, resenias);

	while (leidos > 0){
		imprimir_pelicula(pelicula);
		leidos = fread(&pelicula, sizeof(pelicula_t), 1, resenias);
	}

	fclose(resenias);

	return 0;
}