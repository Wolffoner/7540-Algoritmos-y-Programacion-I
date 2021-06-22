#include <stdio.h>
#include <stdbool.h>

#define MINIMAS_VECES_CACA 1
const int MAXIMAS_VECES_CACA = 100;

/*
 * Pre: -
 * Post: Devolvera TRUE si la cantidad de bolsas
 * 		 está dentro del rango o FALSE si no.
 */
bool es_cantidad_caca_valido(int bolsas){
	if (bolsas >= MINIMAS_VECES_CACA && bolsas <= MAXIMAS_VECES_CACA) {
		return true;
	} else {
		return false;
	}
}

/*
 * Pre:	- bolsas_x_dia entre MAXIMO y MINIMO
 * 		- dias entre ...
 * 		- bolsas_x_rollito entre ...
 * Post: devolvera la cantidad de rollitos necesaria para que Charly este en paz en su estadia 
 */
int cantidad_rollitos(int bolsas_x_dia, int dias, int bolsas_x_rollito){

	int rollitos = ((bolsas_x_dia * dias) / bolsas_x_rollito);

	if ((bolsas_x_dia * dias) % bolsas_x_rollito != 0) {
		rollitos++;
	}

	return rollitos;
}

int main(){
	
	int bolsas_diarias;
	int dias = 180;
	int bolsas_por_rollito = 100;
	char letra = 'A';
	float lot = 1.5;

	if (dias == letra) printf("Hola\n");

	printf("Char, cuantas veces por día hace caca Alma?");
	scanf("%i", &bolsas_diarias);

	while (!es_cantidad_caca_valido(bolsas_diarias)) {
		printf("Char no seas mal tipo, cuantas veces por día hace caca Alma? (entre %i - %i)", MINIMAS_VECES_CACA, MAXIMAS_VECES_CACA);
		scanf("%i", &bolsas_diarias);
	}

	/* Aca pedir los demás datos. */

	printf("Charly, vas a tener que llevar %i rollitos.\n", cantidad_rollitos(bolsas_diarias, dias, bolsas_por_rollito));

	return 0;
}
