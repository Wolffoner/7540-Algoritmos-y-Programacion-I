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
    comidas[*tope].precio = 400;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "aaaanvoooorguesa grasienta con unas birras ;)");
    comidas[*tope].precio = 99999999;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Papas bravas");
    comidas[*tope].precio = 200;
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Asado de Maxi el Bostero");
    comidas[*tope].precio = 999999999;
    comidas[*tope].es_vegana = false;
    comidas[*tope].tiene_tacc = true;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Helado de menta granizada");
    comidas[*tope].precio = 0; // es ilegal
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = false;

    (*tope)++;
    strcpy(comidas[*tope].nombre, "Pizza de anana");
    comidas[*tope].precio = 0; 
    comidas[*tope].es_vegana = true;
    comidas[*tope].tiene_tacc = true;
}

// strcmp(const char*, const char*)
// a == b : 0
// a > b : +
// a < b : -
void ordenar_por_insercion(comida_t comidas[], int tope){
    int k;
    comida_t auxiliar;

    for (int i = 1; i < tope; i++){
        auxiliar = comidas[i];
        k = i;
        while (k > 0 && (strcmp(auxiliar.nombre, comidas[k-1].nombre) < 0)) {

            comidas[k] = comidas[k-1];
            k--;
        }
        comidas[k] = auxiliar;
    }
}

int main () {
    comida_t comidas[MAX_COMIDAS];
    int tope = 0;
    generar_vector_comidas(comidas, &tope);
    ordenar_por_insercion(comidas, tope);
    imprimir_comidas(comidas, tope);

    return 0;
}