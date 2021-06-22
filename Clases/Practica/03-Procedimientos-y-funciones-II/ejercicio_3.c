#include <stdio.h>

const int CANTIDAD_COLABORADORES = 22;
const int MAXIMO_BAJITO = 165;
const char SI = 'S';

/*
 * Poner pre y post condiciones
 */
void mostrar_resultado(int colabs_bajito, int colabs_rieron){
	if ((colabs_bajito >= CANTIDAD_COLABORADORES / 2) && (colabs_rieron > CANTIDAD_COLABORADORES / 2)){
		printf("Me wua mata wiiiii\n");
	} else if ((colabs_bajito < CANTIDAD_COLABORADORES / 2) && (colabs_rieron > CANTIDAD_COLABORADORES / 2)){
		printf("Tu criticando y yo creando mi legado, amen.\n");
	} else if ((colabs_bajito >= CANTIDAD_COLABORADORES / 2) && (colabs_rieron >= CANTIDAD_COLABORADORES / 2)){
		printf("Y es que la noche me busca a mí, salimo' en un coche corte rally.\n");
	} else {
		printf("No es lo que esperaba, pero estoy satisfecho.\n");
	}
	/*
	 * Se puede hacer mas lindo? Las condiciones quedan bien? O convendría modularizar?
	 */
}

/*
 * Poner pre y post condiciones
 */
void encuestar_colabs(int* colabs_bajito, int* colabs_rieron){

	int altura;
	char te_reiste;

	for(int i = 1; i <= CANTIDAD_COLABORADORES; i++){
		printf("Hola colaborador número %i!\n", i);
		printf("¿Cuánto crees que mido? (entre 0 y 200 cm): ");
		scanf("%i", &altura);
		printf("¿Te reíste de mi último chiste? (S/N): ");
		scanf(" %c", &te_reiste);
		/*
		 * Cambiar el programa para que pida los datos en procedimientos aparte.
		 * pedir_altura(&altura);
		 * preguntar_si_se_rio(&te_reiste);
		 */

		if (altura < MAXIMO_BAJITO){
			(*colabs_bajito)++;
		}
		if (te_reiste == SI){
			(*colabs_rieron)++;
		}
	}
}

int main(){
	int colabs_bajito = 0;
	int colabs_rieron = 0;

	encuestar_colabs(&colabs_bajito, &colabs_rieron);
	mostrar_resultado(colabs_bajito, colabs_rieron);

	return 0;
}