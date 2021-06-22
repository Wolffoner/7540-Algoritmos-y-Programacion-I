#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "adopta_amigo.h"

/*
 * Pre: 
 * Pos: Define el caracter de comparacion y retorna la variable 'tamano'
 */
int define_tamano(char* tamano, char* compara_tamano){
	size_t len = strlen(tamano);
	for(int i = 0; i < len; i++){
		if (i == 0){
			*compara_tamano = tamano[i];
			tamano[i] = tamano[i+1];
		} else{
			tamano[i] = tamano[i+1];
		}
	}
	return atoi(tamano);
}

/*
 * Pre: El archivo debe poder abrirse 
 * Pos: Define los requisitos del amigo_ideal, y añade al vector nombres los amigos imaginarios ya adoptados.
 */
void define_requisitos(char* archivo, amigo_t* amigo_ideal, char* compara_tamano, char nombres[MAX_AMIGOS][MAX_NOMBRE], int *tope_nombres){
	FILE *fp;
	amigo_ideal->tope_virtudes = 1;
	amigo_ideal->tope_defectos = 1;
	if((fp = fopen(archivo, "r"))){
		fscanf(fp, FORMATO_REQUISITOS, amigo_ideal->color, compara_tamano, &amigo_ideal->altura, amigo_ideal->virtudes[0].descripcion, amigo_ideal->defectos[0].descripcion);
		while(!feof(fp)){
			fscanf(fp, FORMATO_AMIGOS_ADOPTADOS, nombres[*tope_nombres]);
			*tope_nombres = *tope_nombres + 1;
		}
		fclose(fp);
	}
}

/*
 * Pre: 
 * Pos: Retorna mismo_color que depende de si color_ideal y color_amigo_mansion son iguales o distintos
 */
bool verifica_color_amigo(char* color_ideal, char* color_amigo_mansion){
	bool mismo_color = false;
	if(strcmp(color_ideal, color_amigo_mansion) == 0){
		mismo_color = true;
	}
	return mismo_color;
}

/*
 * Pre: 
 * Pos: Retorna tamano que depende del char compara_tamano y verifica el mismo con los tamaños obtenidos.
 */
bool verifica_tamano_amigo(int tamano_ideal, int tamano_amigo_mansion, char compara_tamano){
	bool tamano = false;
	switch(compara_tamano){
		case MENOR_QUE:
			if(tamano_amigo_mansion < tamano_ideal){
				tamano = true;
			} 
		break;
		case MAYOR_QUE:
			if(tamano_amigo_mansion > tamano_ideal){
				tamano = true;
			} 
		break;
		case IGUAL_QUE:
			if(tamano_amigo_mansion == tamano_ideal){
				tamano = true;
			} 
		break;
		default:
		break;
	}
	return tamano;
}

/*
 * Pre: 
 * Pos: Retorna tiene_virtud, si la virtud del amigo_ideal es igual a alguna del amigo_mansion
 */
bool verifica_virtud(amigo_t amigo_ideal, amigo_t amigo_mansion){
	bool tiene_virtud = false;
	for(int i = 0; i < amigo_mansion.tope_virtudes; i++){
		if(strcmp(amigo_ideal.virtudes[0].descripcion, amigo_mansion.virtudes[i].descripcion) == STRING_IGUALES){
			tiene_virtud = true;
		}
	}
	return tiene_virtud;
}

/*
 * Pre: 
 *  Pos: Retorna tiene_defecto, dependiendo si el defecto del amigo_ideal es distinto a alguno del amigo_mansion
 */
bool verifica_defecto(amigo_t amigo_ideal, amigo_t amigo_mansion){
	bool tiene_defecto = true;
	for(int i = 0; i < amigo_mansion.tope_defectos; i++){
		if(strcmp(amigo_ideal.defectos[0].descripcion, amigo_mansion.defectos[i].descripcion) == STRING_IGUALES){
			tiene_defecto = false;
		}
	}
	return tiene_defecto;
}

/*
 * Pre: 
 * Pos: Retorna es_adoptable, dependiendo si el amigo_mansion esta en la mansion
 */
bool verifica_esta_mansion(amigo_t amigo_mansion){
	bool es_adoptable = false;
	if(amigo_mansion.esta_en_mansion){
		es_adoptable = true;
	}
	return es_adoptable;
}

/*
 * Pre: 
 * Pos: Retorna no_fue_adoptado, dependiendo si el amigo_mansion esta en la lista de amigos ya adoptados por el niño.
 */
bool verifica_fue_adoptado(amigo_t amigo_mansion, char amigos_adoptados[MAX_AMIGOS][MAX_NOMBRE], int tope_amigos_adoptados){
	bool no_fue_adoptado = true;
	for( int i = 0; i < tope_amigos_adoptados; i++){
		if(strcmp(amigo_mansion.nombre, amigos_adoptados[i]) == STRING_IGUALES){
			no_fue_adoptado = false;
		}
	}
	return no_fue_adoptado;
}

/*
 * Pre: 
 * Pos: Retorna es_ideal, si el amigo es apto o no apto para adoptar.
 */
bool verifica_amigo_ideal(amigo_t amigo_ideal, amigo_t amigo_mansion, char compara_tamano, char amigos_adoptados[MAX_AMIGOS][MAX_NOMBRE], int tope_amigos_adoptados){
	bool es_ideal = false;
	if( verifica_color_amigo(amigo_ideal.color, amigo_mansion.color) &&
			verifica_tamano_amigo(amigo_ideal.altura, amigo_mansion.altura, compara_tamano) &&
			verifica_virtud(amigo_ideal, amigo_mansion) &&
			verifica_defecto(amigo_ideal, amigo_mansion) &&
			verifica_esta_mansion(amigo_mansion) &&
			verifica_fue_adoptado(amigo_mansion, amigos_adoptados, tope_amigos_adoptados)){
		es_ideal = true;
	}
	return es_ideal;
}
 
/*
 * Pre: 
 * Pos: Se define la variable nombre del amigo ideal para adoptar
 */
void busca_amigo_ideal(amigo_t amigo_ideal, char compara_tamano, char *nombre, char amigos_adoptados[MAX_AMIGOS][MAX_NOMBRE], int tope_amigos_adoptados){
	amigo_t amigo_mansion;
	amigo_t amigo_posible;
	FILE *file;
	if((file = fopen(PATH_AMIGOS, "rb"))){
		while(fread(&amigo_mansion, sizeof(amigo_mansion), 1, file) == SIZE_READ){
			if(verifica_amigo_ideal(amigo_ideal, amigo_mansion, compara_tamano, amigos_adoptados, tope_amigos_adoptados)){
				amigo_posible = amigo_mansion;
			}
		}
		fclose(file);
		strncpy(nombre, amigo_posible.nombre, MAX_NOMBRE);
	}
}
 
/*
 * Pre:
 * Pos: Modifica el archivo y agrega el amigo ideal a la lista de amigos adoptados.
 */
void adopta_amigo_ideal(char* archivo, char *nombre_amigo_escogido){
	FILE *fp;
	if((fp = fopen(archivo, "a"))){
		fputs(nombre_amigo_escogido, fp);
		fputs("\n", fp);
		fclose(fp);
	}
}
 
/*
 * Pre: 
 * Pos: Modifica si un amigo imaginario esta o no esta en la mansion
 */
bool cambia_lugar(char* archivo, char* nombre_amigo, bool esta_mansion){
	amigo_t amigo_mansion;
	FILE *file;
	bool modificado = false;
	if ((file = fopen(archivo, "r+b"))){
		while(fread(&amigo_mansion, sizeof(amigo_t), 1, file) != EOF && !modificado ){
			if(strcmp(nombre_amigo, amigo_mansion.nombre) == 0 ){
				fseek(file, (-1)*(int)sizeof(amigo_t), SEEK_CUR);
				amigo_mansion.esta_en_mansion = esta_mansion;
				fwrite(&amigo_mansion, sizeof(amigo_t), 1, file);
				fflush(file);
				modificado = true;
			}	
		}
		fclose(file);
	}
	return modificado;
}

/*
 * Pre: archivo se debe poder abrir.
 * Pos: Imprime por consola los amigos que estan actualmente en la mansion
 */
bool lista_amigos_disponibles(char* archivo){
	amigo_t amigo_mansion;
	FILE *file;
	bool listado = false;
	if((file = fopen(archivo, "rb"))){
		while( fread(&amigo_mansion, sizeof(amigo_mansion), 1, file) == SIZE_READ){
			if(amigo_mansion.esta_en_mansion){
				printf("%s\n", amigo_mansion.nombre);
			}
		}
		fclose(file);
		listado = true;
	}
	return listado;
}

int elegir_amigo(char* archivo){
	int amigo_elegido = 0;
	amigo_t amigo_ideal;
	char compara_tamano;
	char nombre_amigo_escogido[MAX_NOMBRE] = "";
	char amigos_adoptados[MAX_AMIGOS][MAX_NOMBRE];
	int tope_amigos_adoptados = 0;
	define_requisitos(archivo, &amigo_ideal, &compara_tamano, amigos_adoptados, &tope_amigos_adoptados);	
	busca_amigo_ideal(amigo_ideal, compara_tamano, nombre_amigo_escogido, amigos_adoptados, tope_amigos_adoptados);
	if(strcmp(nombre_amigo_escogido, "") != STRING_IGUALES){
		adopta_amigo_ideal(archivo, nombre_amigo_escogido);
		cambia_lugar(PATH_AMIGOS, nombre_amigo_escogido, NO_ESTA_MANSION);
		amigo_elegido = 1;
	}
	return amigo_elegido;
}

int listar_amigos(char* archivo){
	int lista_amigos = 0;
	if(lista_amigos_disponibles(archivo)){
		lista_amigos = 1;
	}
	return lista_amigos;
}

int devolver_amigo(char* archivo, char* nombre_amigo){
	int amigo_devuelto = 0;
	if(cambia_lugar(archivo, nombre_amigo, ESTA_MANSION)){
		amigo_devuelto = 1;
	}
	return amigo_devuelto;
}
