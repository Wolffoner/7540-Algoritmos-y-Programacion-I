#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define MAX_HORTALIZAS 2500
#define MAX_NOMBRE 50
#define MAX_SURCOS 50
#define MAX_HORTALIZAS_POR_SURCOS 50
#define MAX_CHOCLO 2500
#define MAX_COLABS 23


const char CHOCLO = 'C';
const int PRECIO_REGALO = 1000;

typedef struct coordenada{
	int fil;
	int col;
}coordenada_t;

typedef struct hortaliza{
	char nombre;
	int precio_de_lista;
} hortaliza_t;

typedef struct huerta{
	hortaliza_t hortalizas[MAX_SURCOS][MAX_HORTALIZAS_POR_SURCOS];
	int cantidad_surcos;
	int cantidad_hortalizas_por_surcos;
} huerta_t;


typedef struct colaborador{
	char nombre [MAX_NOMBRE];
	hortaliza_t frutas_y_verduras[MAX_HORTALIZAS];
	int cantidad_hortalizas;
}colaborador_t;

typedef struct ratas{
	char nombre[MAX_NOMBRE];
	int deuda;
}ratas_t;


void inicializar_huerta(huerta_t* huerta){
	huerta->cantidad_surcos = 5;
	huerta->cantidad_hortalizas_por_surcos = 5;
	huerta->hortalizas[0][0].nombre = 'C';
	huerta->hortalizas[0][0].precio_de_lista = 250;	
	huerta->hortalizas[0][1].nombre = 'T';
	huerta->hortalizas[0][1].precio_de_lista = 30;	
	huerta->hortalizas[0][2].nombre = 'L';
	huerta->hortalizas[0][2].precio_de_lista = 300;	
	huerta->hortalizas[0][3].nombre = 'C';
	huerta->hortalizas[0][3].precio_de_lista = 250;	
	huerta->hortalizas[0][4].nombre = 'T';
	huerta->hortalizas[0][4].precio_de_lista = 30;	

	huerta->hortalizas[1][0].nombre = 'L';
	huerta->hortalizas[1][0].precio_de_lista = 300;	
	huerta->hortalizas[1][1].nombre = 'L';
	huerta->hortalizas[1][1].precio_de_lista = 300;	
	huerta->hortalizas[1][2].nombre = 'C';
	huerta->hortalizas[1][2].precio_de_lista = 250;	
	huerta->hortalizas[1][3].nombre = 'Z';
	huerta->hortalizas[1][3].precio_de_lista = 50;	
	huerta->hortalizas[1][4].nombre = 'Z';
	huerta->hortalizas[1][4].precio_de_lista = 50;

	huerta->hortalizas[2][0].nombre = 'Z';
	huerta->hortalizas[2][0].precio_de_lista = 50;
	huerta->hortalizas[2][1].nombre = 'L';
	huerta->hortalizas[2][1].precio_de_lista = 300;
	huerta->hortalizas[2][2].nombre = 'T';
	huerta->hortalizas[2][2].precio_de_lista = 30;
	huerta->hortalizas[2][3].nombre = 'T';
	huerta->hortalizas[2][3].precio_de_lista = 30;
	huerta->hortalizas[2][4].nombre = 'L';
	huerta->hortalizas[2][4].precio_de_lista = 300;

	huerta->hortalizas[3][0].nombre = 'T';
	huerta->hortalizas[3][0].precio_de_lista = 30;
	huerta->hortalizas[3][1].nombre = 'A';
	huerta->hortalizas[3][1].precio_de_lista = 100;
	huerta->hortalizas[3][2].nombre = 'A';
	huerta->hortalizas[3][2].precio_de_lista = 100;
	huerta->hortalizas[3][3].nombre = 'C';
	huerta->hortalizas[3][3].precio_de_lista = 250;
	huerta->hortalizas[3][4].nombre = 'A';
	huerta->hortalizas[3][4].precio_de_lista = 100;

	huerta->hortalizas[4][0].nombre = 'C';
	huerta->hortalizas[4][0].precio_de_lista = 250;
	huerta->hortalizas[4][1].nombre = 'C';
	huerta->hortalizas[4][1].precio_de_lista = 250;
	huerta->hortalizas[4][2].nombre = 'L';
	huerta->hortalizas[4][2].precio_de_lista = 300;
	huerta->hortalizas[4][3].nombre = 'A';
	huerta->hortalizas[4][3].precio_de_lista = 100;
	huerta->hortalizas[4][4].nombre = 'C';
	huerta->hortalizas[4][4].precio_de_lista = 250;
}

void imprimir_huerta(huerta_t huerta){
	for(int i = 0; i<huerta.cantidad_surcos; i++){
		for(int j = 0; j<huerta.cantidad_hortalizas_por_surcos; j++){
			printf("[%c] ",huerta.hortalizas[i][j].nombre);
		}
		printf("\n");
	}
}

// PRE: tope >= 0, huerta debe estar inicializada
// POST: agrega a coordenadas_choclo las posiciones de los choclos que hay en la huerta
void encontrar_choclitos(huerta_t huerta, coordenada_t coordenadas_choclo[MAX_CHOCLO], int* tope){
	for(int i=0; i<huerta.cantidad_surcos; i++){
		for(int j= 0; j< huerta.cantidad_hortalizas_por_surcos;j++){
			if(huerta.hortalizas[i][j].nombre == CHOCLO){
				coordenadas_choclo[*tope].fil = i;
				coordenadas_choclo[*tope].col = j;
				(*tope)++;
			}
		}
	}
}

void imprimir_choclos(coordenada_t coordenadas_choclo[MAX_CHOCLO], int tope){
	for(int i = 0;i<tope;i++){
		printf("Fila: %i, Columna: %i\n", coordenadas_choclo[i].fil,coordenadas_choclo[i].col);
	}
}


void inicializar_regalos(colaborador_t regalitos_colabs[MAX_COLABS], int* cantidad_regalos){
	strcpy(regalitos_colabs[0].nombre,"Manu");
	regalitos_colabs[0].frutas_y_verduras[0].nombre = 'T';
	regalitos_colabs[0].frutas_y_verduras[0].precio_de_lista = 3000;
	regalitos_colabs[0].frutas_y_verduras[1].nombre = 'L';
	regalitos_colabs[0].frutas_y_verduras[1].precio_de_lista = 300;
	regalitos_colabs[0].frutas_y_verduras[2].nombre = 'T';
	regalitos_colabs[0].frutas_y_verduras[2].precio_de_lista = 30;
	regalitos_colabs[0].frutas_y_verduras[3].nombre = 'Z';
	regalitos_colabs[0].frutas_y_verduras[3].precio_de_lista = 50;
	regalitos_colabs[0].frutas_y_verduras[4].nombre = 'C';
	regalitos_colabs[0].frutas_y_verduras[4].precio_de_lista = 250;
	regalitos_colabs[0].cantidad_hortalizas = 5;

	strcpy(regalitos_colabs[1].nombre,"Santi");
	regalitos_colabs[1].frutas_y_verduras[0].nombre = 'C';
	regalitos_colabs[1].frutas_y_verduras[0].precio_de_lista = 250;
	regalitos_colabs[1].frutas_y_verduras[1].nombre = 'C';
	regalitos_colabs[1].frutas_y_verduras[1].precio_de_lista = 250;
	regalitos_colabs[1].frutas_y_verduras[2].nombre = 'C';
	regalitos_colabs[1].frutas_y_verduras[2].precio_de_lista = 250;
	regalitos_colabs[1].frutas_y_verduras[3].nombre = 'C';
	regalitos_colabs[1].frutas_y_verduras[3].precio_de_lista = 250;
	regalitos_colabs[1].frutas_y_verduras[4].nombre = 'C';
	regalitos_colabs[1].frutas_y_verduras[4].precio_de_lista = 250;
	regalitos_colabs[1].cantidad_hortalizas = 5;

	strcpy(regalitos_colabs[2].nombre,"Charly");
	regalitos_colabs[2].frutas_y_verduras[0].nombre = 'L';
	regalitos_colabs[2].frutas_y_verduras[0].precio_de_lista = 300;
	regalitos_colabs[2].frutas_y_verduras[1].nombre = 'L';
	regalitos_colabs[2].frutas_y_verduras[1].precio_de_lista = 300;
	regalitos_colabs[2].frutas_y_verduras[2].nombre = 'L';
	regalitos_colabs[2].frutas_y_verduras[2].precio_de_lista = 300;
	regalitos_colabs[2].frutas_y_verduras[3].nombre = 'Z';
	regalitos_colabs[2].frutas_y_verduras[3].precio_de_lista = 50;
	regalitos_colabs[2].frutas_y_verduras[4].nombre = 'C';
	regalitos_colabs[2].frutas_y_verduras[4].precio_de_lista = 250;
	regalitos_colabs[2].cantidad_hortalizas = 5;

	strcpy(regalitos_colabs[3].nombre,"Sol");
	regalitos_colabs[3].frutas_y_verduras[0].nombre = 'A';
	regalitos_colabs[3].frutas_y_verduras[0].precio_de_lista = 100;
	regalitos_colabs[3].frutas_y_verduras[1].nombre = 'L';
	regalitos_colabs[3].frutas_y_verduras[1].precio_de_lista = 300;
	regalitos_colabs[3].frutas_y_verduras[2].nombre = 'A';
	regalitos_colabs[3].frutas_y_verduras[2].precio_de_lista = 100;
	regalitos_colabs[3].frutas_y_verduras[3].nombre = 'Z';
	regalitos_colabs[3].frutas_y_verduras[3].precio_de_lista = 50;
	regalitos_colabs[3].frutas_y_verduras[4].nombre = 'C';
	regalitos_colabs[3].frutas_y_verduras[4].precio_de_lista = 250;
	regalitos_colabs[3].cantidad_hortalizas = 5;

	strcpy(regalitos_colabs[4].nombre,"Delfi");
	regalitos_colabs[4].frutas_y_verduras[0].nombre = 'A';
	regalitos_colabs[4].frutas_y_verduras[0].precio_de_lista = 100;
	regalitos_colabs[4].frutas_y_verduras[1].nombre = 'A';
	regalitos_colabs[4].frutas_y_verduras[1].precio_de_lista = 100;
	regalitos_colabs[4].frutas_y_verduras[2].nombre = 'A';
	regalitos_colabs[4].frutas_y_verduras[2].precio_de_lista = 100;
	regalitos_colabs[4].frutas_y_verduras[3].nombre = 'Z';
	regalitos_colabs[4].frutas_y_verduras[3].precio_de_lista = 50;
	regalitos_colabs[4].frutas_y_verduras[4].nombre = 'Z';
	regalitos_colabs[4].frutas_y_verduras[4].precio_de_lista = 50;
	regalitos_colabs[4].cantidad_hortalizas = 5;

	strcpy(regalitos_colabs[5].nombre,"Rena");
	regalitos_colabs[5].frutas_y_verduras[0].nombre = 'L';
	regalitos_colabs[5].frutas_y_verduras[0].precio_de_lista = 300;
	regalitos_colabs[5].frutas_y_verduras[1].nombre = 'L';
	regalitos_colabs[5].frutas_y_verduras[1].precio_de_lista = 300;
	regalitos_colabs[5].frutas_y_verduras[2].nombre = 'A';
	regalitos_colabs[5].frutas_y_verduras[2].precio_de_lista = 100;
	regalitos_colabs[5].frutas_y_verduras[3].nombre = 'Z';
	regalitos_colabs[5].frutas_y_verduras[3].precio_de_lista = 50;
	regalitos_colabs[5].frutas_y_verduras[4].nombre = 'L';
	regalitos_colabs[5].frutas_y_verduras[4].precio_de_lista = 300;
	regalitos_colabs[5].cantidad_hortalizas = 5;

	(*cantidad_regalos) = 6;
}

void imprimir_colabs(colaborador_t regalitos_colabs[MAX_COLABS], int tope){
	for(int i = 0; i<tope; i++){
		printf("%s\n",regalitos_colabs[i].nombre);
	}
}


void crear_vector_de_ratas(colaborador_t colaboradores[MAX_COLABS],int tope, ratas_t ratas[MAX_COLABS], int* tope_deudores){
	int suma;
	for(int i = 0; i<tope;i++){
		suma = 0;
		for(int j = 0; j<colaboradores[i].cantidad_hortalizas;j++){
			suma = colaboradores[i].frutas_y_verduras[j].precio_de_lista + suma;
		}
		if(suma > PRECIO_REGALO){
			strcpy(ratas[*tope_deudores].nombre,colaboradores[i].nombre);
			ratas[*tope_deudores].deuda = suma - PRECIO_REGALO;
			(*tope_deudores) ++;
		}
	}
}

void imprimir_ratas(ratas_t ratas[MAX_COLABS], int tope){
	for(int i = 0; i<tope; i++){
		printf("Los ratas son: %s\n",ratas[i].nombre);
	}
}
int main(){

	huerta_t huerta;
	coordenada_t coordenadas_choclo[MAX_CHOCLO];
	int tope = 0;
	inicializar_huerta(&huerta);
	imprimir_huerta(huerta);
	encontrar_choclitos(huerta,coordenadas_choclo,&tope);
	imprimir_choclos(coordenadas_choclo,tope);

	colaborador_t regalitos_colabs[MAX_COLABS];
	int cantidad_regalos = 0;
	ratas_t ratas[MAX_COLABS];
	int tope_ratas = 0;
	inicializar_regalos(regalitos_colabs,&cantidad_regalos);
	imprimir_colabs(regalitos_colabs,cantidad_regalos);

	crear_vector_de_ratas(regalitos_colabs,cantidad_regalos,ratas,&tope_ratas);
	imprimir_ratas(ratas,tope_ratas);


	return 0;
}