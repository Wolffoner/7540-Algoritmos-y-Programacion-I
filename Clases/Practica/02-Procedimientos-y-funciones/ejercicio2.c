#include <stdio.h>
#include <stdbool.h>

const char TRIANGULAR = 'T';
const char CIRCULAR = 'O';
const char CUADRADA = 'C';

const char CARNE = 'C';
const char VEGETAL = 'V'; 
const char POLLO = 'P';

const int CHICO = 2;
const int MEDIANO = 4;
const int GRANDE = 6;




bool es_forma_valida(char forma){
	return (forma == CUADRADA || forma == CIRCULAR || forma == TRIANGULAR);
}

bool es_sabor_valido(char sabor){
	return (sabor == CARNE || sabor == POLLO || sabor == VEGETAL);
}

bool es_tamanio_valido(int tamanio){
	return (tamanio == CHICO || tamanio == MEDIANO || tamanio == GRANDE);
}

/*
PRE: 
Forma debe ser TRIANGULAR, CIRCULAR, CUADRADA.
Sabor debe ser CARNE, VEGETAL o POLLO.
Tamanio debe ser CHICO, MEDIANO, GRANDE.

POST: 
Devolvera true si es aceptado por alma, false en caso contrario
*/
bool aceptado_por_alma(char forma, char sabor, int tamanio){

//FORMA 1
	return (forma != CUADRADA && sabor == VEGETAL && tamanio == CHICO);


//FORMA 2 
/*
	bool aceptada = false;

	if(forma != CUADRADA){
		if(sabor == VEGETAL){
			if(tamanio == CHICO){
				aceptada = true;
			}
		}
	}

	return aceptada;
*/

// FORMA 3 
/*	
	bool aceptada = false;

	if(forma != CUADRADA && sabor == VEGETAL && tamanio == CHICO){
		aceptada = true;
	}

	return aceptada;
*/


int main(){
	
	char forma;
	char sabor;
	int tamanio;
	bool aceptada;


	printf("Tirame la forma de la comida (%c,%c,%c):", CUADRADA, TRIANGULAR, CIRCULAR);
	scanf(" %c", &forma);

	while(!es_forma_valida(forma)){
		printf("Esa forma no existe. Tiramela bien (%c,%c,%c):", CUADRADA, TRIANGULAR, CIRCULAR);
		scanf(" %c", &forma);
	}

	printf("Ahora tirame el sabor (%c,%c,%c):",CARNE,POLLO,VEGETAL);	
	scanf(" %c", &sabor);

	while(!es_sabor_valido(sabor)){
		printf("Ese sabor no existe. Tiramelo bien (%c,%c,%c):",CARNE,POLLO,VEGETAL);
		scanf(" %c", &sabor);
	}

	printf("Y por ultimo, el tamanio (%i,%i,%i):",CHICO,MEDIANO,GRANDE);
	scanf("%i", &tamanio);

	while(!es_tamanio_valido(tamanio)){
		printf("Ese tamanio no existe. Tiramelo bien (%i,%i,%i):",CHICO,MEDIANO,GRANDE);
		scanf("%i", &tamanio);
	}

	aceptada = aceptado_por_alma(forma,sabor, tamanio);

	if(aceptada == true){
		printf("Alma lo acepto\n");
	}else{
		printf("F por Alma");
	}

	return 0;
}