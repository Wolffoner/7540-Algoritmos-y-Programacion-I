#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 100
#define MAX_PATH 150
#define PATH_COLABS "colabs.dat"
/* 
El profesor Cangrejo siempre que quiere hacer un asado tiene problemas de logística, 
debe preguntar uno por uno a los colaboradores si : 
- Si come carne.
- Si tiene auto para ir por su cuenta.
Para eso decidió hacer un archivo binario donde guarda esta información crucial de cada uno de sus colaboradores.
Partiendo del hecho que el archivo ya esta hecho (y bien formado), implementar las siguientes funciones : 
*/

/*
void hacer_vegano (char path [MAX_PATH] , int id);
void hacer_carnivoro(char path [MAX_PATH], int id);
void asignar_auto(char path [MAX_PATH], int id);
void sacar_auto(char path [MAX_PATH], int id);
*/
typedef struct colaborador {
    int id;
    char nombre [MAX_NOMBRE];
    bool es_vegano;
    bool tiene_auto;
} colaborador_t;

void mostrar_colaborador (colaborador_t colab) {
    for (size_t i = 0; i < 50; i++)  printf("-");
    printf("\n");

    printf("ID : %i, ", colab.id);
    printf("Nombre : %s \n", colab.nombre);
    printf("- %s \n", colab.es_vegano ? "No come carne" : "Come carne" );
    printf("- %s \n", colab.tiene_auto ? "Tiene auto" : "L@ tienen que pasar a buscar" );
    printf("\n");
}

void mostrar_colabs (char path [MAX_PATH]) {
    FILE* archivo = fopen(path,"r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s", path);
        return;
    }
    int leidos = 0;
    colaborador_t colab_actual;
    do {
        leidos = fread(&colab_actual,sizeof(colaborador_t), 1, archivo);
        if (leidos == 1) {
            mostrar_colaborador(colab_actual);
        }
    } while (leidos == 1);
    fclose(archivo);
}

//función hardcodeada para hacer el ejercicio
colaborador_t generar_colab(int id, char nombre [MAX_NOMBRE]) {
    colaborador_t aux;
    aux.id = id;
    strcpy(aux.nombre, nombre);
    int r = rand()%2;
    aux.es_vegano = (r==1) ? true : false;
    r = rand()%2;
    aux.tiene_auto = (r==1) ? true : false;
    return aux;
}

//esta función esta toda hardcodeada, es usada con fines de dar la clase
void cargar_colabs(char path [MAX_PATH]) {
    srand(time(NULL));
    FILE* archivo = fopen(path,"w");
    if (archivo == NULL) {
        printf("No se pudo generar el archivo %s", path);
        return;
    }
    int i = 0;
    colaborador_t aux;
    aux = generar_colab (i, "Agustina Bocaccio");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Candela Serrano");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Candela Zeida");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Celeste Dituro");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++; 

    aux = generar_colab (i, "Charly Talavera");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++; 

    aux = generar_colab (i, "Delfina Garcia Villamor");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++; 
    
    aux = generar_colab (i, "Franco Prime");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Julian Benitez");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Manuel Bilbao");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Manuel Camejo");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Maria Del Rosario Presedo");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Mariano Mendez");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Matias Gonzalez");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Melina Lazaro");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Nahuel Castro");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Nicolas Riedel");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Renata Victorina Vidal");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Santiago Fernandez");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Santiago Locatelli");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Sol Diaz Real");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Stephanie Castillo");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    aux = generar_colab (i, "Tomas Rodriguez Dala");
    fwrite(&aux, sizeof(colaborador_t), 1, archivo);
    i++;

    fclose(archivo);
}


void mostrar_opciones () {
    printf ("-Ingrese L para listar todos los colaboradores \n");
    printf ("-Ingrese V para volver a un colaborador vegano \n");
    printf ("-Ingrese C para volver a un colaborador carnívoro \n");
    printf ("-Ingrese A para indicar que un colaborador ahora dispone de auto \n");
    printf ("-Ingrese F para indicar que un colaborador dejo de tener auto \n");
    printf ("- Ingrese cualquier otro carácter para terminar la ejecución del programa\n");
}

bool opcion_valida (char opcion) {
    return (opcion == 'L' || 
            opcion == 'V' ||
            opcion == 'C' ||
            opcion == 'A' ||
            opcion == 'F');
}

int pedir_id(){
    printf("Ingrese el id asociado al colab que quiere modificar\n");
    int id;
    scanf(" %i", &id);
    return id;;
}


void hacer_vegano (char path [MAX_PATH] , int id) {
    FILE* archivo = fopen(path,"r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s", path);
        return;
    }
    colaborador_t colab_buscado;
    fseek(archivo, id*sizeof(colaborador_t), SEEK_SET);
    int leidos = fread(&colab_buscado, sizeof(colaborador_t), 1 , archivo);
    if (leidos != 1) {
        printf("Ocurrio un error intentado leer el colab numero %i \n", id);
        return;
    }

    if(colab_buscado.es_vegano){
        printf("ERROR : %s ya es vegan@\n", colab_buscado.nombre);
    } else {
        colab_buscado.es_vegano = true;
        fseek(archivo, -sizeof(colaborador_t), SEEK_CUR);
        fwrite(&colab_buscado, sizeof(colaborador_t), 1, archivo);
    }

    fclose(archivo);
}

void hacer_carnivoro(char path [MAX_PATH], int id) {
    FILE* archivo = fopen(path,"r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s", path);
        return;
    }
    colaborador_t colab_buscado;
    fseek(archivo, id*sizeof(colaborador_t), SEEK_SET);
    int leidos = fread(&colab_buscado, sizeof(colaborador_t), 1 , archivo);
    if (leidos != 1) {
        printf("Ocurrio un error intentado leer el colab numero %i \n", id);
        return;
    }

    if( !colab_buscado.es_vegano ){
        printf("ERROR : %s ya es carnivor@\n", colab_buscado.nombre);
    } else {
        colab_buscado.es_vegano = false;
        fseek(archivo, -sizeof(colaborador_t), SEEK_CUR);
        fwrite(&colab_buscado, sizeof(colaborador_t), 1, archivo);
    }

    fclose(archivo);
}

void asignar_auto(char path [MAX_PATH], int id) {
    FILE* archivo = fopen(path,"r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s", path);
        return;
    }
    colaborador_t colab_buscado;
    fseek(archivo, id*sizeof(colaborador_t), SEEK_SET);
    int leidos = fread(&colab_buscado, sizeof(colaborador_t), 1 , archivo);
    if (leidos != 1) {
        printf("Ocurrio un error intentado leer el colab numero %i \n", id);
        return;
    }

    if( colab_buscado.tiene_auto ){
        printf("ERROR : %s ya tiene auto\n", colab_buscado.nombre);
    } else {
        colab_buscado.tiene_auto = true;
        fseek(archivo, -sizeof(colaborador_t), SEEK_CUR);
        fwrite(&colab_buscado, sizeof(colaborador_t), 1, archivo);
    }

    fclose(archivo);
}

void sacar_auto(char path [MAX_PATH], int id) {
    FILE* archivo = fopen(path,"r+");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s", path);
        return;
    }
    colaborador_t colab_buscado;
    fseek(archivo, id*sizeof(colaborador_t), SEEK_SET);
    int leidos = fread(&colab_buscado, sizeof(colaborador_t), 1 , archivo);
    if (leidos != 1) {
        printf("Ocurrio un error intentado leer el colab numero %i \n", id);
        return;
    }

    if( !colab_buscado.tiene_auto ){
        printf("ERROR : %s no tiene auto\n", colab_buscado.nombre);
    } else {
        colab_buscado.tiene_auto = false;
        fseek(archivo, -sizeof(colaborador_t), SEEK_CUR);
        fwrite(&colab_buscado, sizeof(colaborador_t), 1, archivo);
    }
    fclose(archivo);
}

int main () {
    mostrar_colabs(PATH_COLABS);
    char opcion = 'L';

    while (opcion_valida(opcion)) {
        switch (opcion) {
        case 'L':
            mostrar_colabs(PATH_COLABS);
            break;
        case 'V':
            hacer_vegano(PATH_COLABS, pedir_id() );
            break;
        case 'C':
            hacer_carnivoro(PATH_COLABS, pedir_id() );
            break;
        case 'A':
            asignar_auto(PATH_COLABS, pedir_id() );
            break;
        case 'F':
            sacar_auto(PATH_COLABS, pedir_id() );
            break;
        }
        mostrar_opciones();
        scanf(" %c", &opcion);
    }

    return 0;
}