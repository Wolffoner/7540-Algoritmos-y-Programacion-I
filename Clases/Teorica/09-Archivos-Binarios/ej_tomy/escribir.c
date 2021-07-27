#include <stdio.h>
#include <stdbool.h>

#define MAX_NOMBRE 25
typedef struct pelicula{
	char nombre[MAX_NOMBRE];
	short anio;
	bool pasa_bechdel_test;
	char opinion; //B: bueno, R: regular, M: malo
}pelicula_t;

void pedir_pelicula(pelicula_t *pelicula){
	printf("Nombre: \n");
	scanf("%[^\n]", pelicula->nombre);
	printf("Año: \n");
	scanf("%hi", &pelicula->anio);
	printf("Pasa el test de Bechdel?\n");
	printf("S para sí\nOtra letra para no\n");
	char respuesta;
	scanf(" %c", &respuesta);
	pelicula->pasa_bechdel_test = respuesta == 'S';
	printf("Cual fue tu opinión?\n");
	printf("B: bueno, R: regular, M: malo\n");
	scanf(" %c", &pelicula->opinion);
}

int main(){
	FILE* resenias = fopen("reseñas.dat", "a");
	if (resenias == NULL){
		printf("No se puede abrir el archivo.\n");
		return -1;
	}

	pelicula_t pelicula;
	pedir_pelicula(&pelicula);

	fwrite(&pelicula, sizeof(pelicula_t), 1, resenias);

	fclose(resenias);
	return 0;
}