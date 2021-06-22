#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 50
#define MAX_COMIDAS 50

typedef struct comida {

	char nombre[MAX_NOMBRE];
	bool es_vegana;
	bool tiene_tacc;
	int precio;
}comida_t;


void imprimir_comidas(comida_t comidas[], int tope){
    for (int i = 0; i < tope; i++) {
        printf("La comida es: %s\n", comidas[i].nombre);
        printf("\t- Precio: %i\n", comidas[i].precio);
        comidas[i].es_vegana ? printf("\t- Es vegana\n") : printf("\t- NO es vegana\n");
        comidas[i].tiene_tacc ? printf("\t- Tiene tacc\n") : printf("\t- NO tiene tacc\n");
    }
    printf("Tiene %i comidas.\n", tope);
}

void generar_vector_comidas(comida_t comidas[], int* tope){
    // puede comer rena
    *tope = 0;
    strcpy(comidas[*tope].nombre, "Guacamole");
    comidas[*tope].precio = 100;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    // puede comer rena
    (*tope)++;
    strcpy(comidas[*tope].nombre, "Albondigas de espinaca");
    comidas[*tope].precio = 565;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Bife de Lomo con hongos");
    comidas[*tope].precio = 1000;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Choripan de la costanera");
    comidas[*tope].precio = 200;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Fideos con salsa mediterranea");
    comidas[*tope].precio = 20;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Aaaanvoooorguesa grasienta con unas birras ;)");
    comidas[*tope].precio = 300;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Papas bravas");
    comidas[*tope].precio = 200;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Asado de Maxi el Bostero");
    comidas[*tope].precio = 500;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Helado de menta granizada");
    comidas[*tope].precio = 5; // es ilegal
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Pizza de anana");
    comidas[*tope].precio = 10; 
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = true;
}

void ordenar(comida_t comidas[],int tope){
	int i,j;
	comida_t auxiliar;
	for(i=1;i<tope;i++){
		j=i;
		auxiliar = comidas[i];
		while((j>0) && (strcmp(auxiliar.nombre,comidas[j-1].nombre) < 0)){
			comidas[j] = comidas[j-1];
			j--;
		}
		comidas[j] = auxiliar;
	}
}

int buscar_anvorguesa(comida_t comidas[MAX_COMIDAS], int cantidad_comidas){
	int inicio = 0;
	int fin = cantidad_comidas -1;
	int centro;
	int posicion = -1;

	while(posicion == -1 && inicio <= fin){
		centro = (inicio + fin) / 2;
		if(strcmp(comidas[centro].nombre,"Hamburguesa") == 0){
			posicion = centro;
		} else if(strcmp(comidas[centro].nombre, "Hamburguesa") > 0){
			fin = centro - 1;
		} else{
			inicio = centro + 1;
		}
	}
	return posicion;
}

int main(){

	comida_t comidas[MAX_COMIDAS];
	int cantidad_comidas = 0;
	generar_vector_comidas(comidas, &cantidad_comidas);
    ordenar(comidas,cantidad_comidas);
    imprimir_comidas(comidas, cantidad_comidas);

    int posicion = buscar_anvorguesa(comidas,cantidad_comidas);
    printf("Esta en la posicion %i\n",posicion);


	return 0;
}