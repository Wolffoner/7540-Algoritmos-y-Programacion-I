#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_ORDENADO 10
#define MAX_DESORDENADO 10

void insertar_ordenado(int vector_ordenado[MAX_ORDENADO],int* tope, int inserto){
	int i= (*tope);
	while( i>0 && vector_ordenado[i-1]>inserto){
		vector_ordenado[i]= vector_ordenado[i-1];
		i--;
	}
	vector_ordenado[i]= inserto;
	(*tope)++;
}

void insertar_desordenado(int vector_desordenado[MAX_DESORDENADO],int* tope, int inserto){
	vector_desordenado[(*tope)]= inserto;
	(*tope)++;
}

void eliminar_ordenado(int vector_ordenado[MAX_ORDENADO],int* tope, int elimino){
	bool encontre=false;
	int i=0;
	int posicion=0;
	while(i < (*tope) && !encontre){
		if(vector_ordenado[i]== elimino){
			encontre=true;
			posicion= i;
		}
		i++;
	}
	if(encontre){
		for (int i = posicion; i < (*tope); ++i){
			vector_ordenado[i]=vector_ordenado[i+1];
		}
		(*tope)--;
	}

}

void eliminar_desordenado(int vector_desordenado[MAX_DESORDENADO],int* tope, int elimino){
	bool encontre=false;
	int i=0;
	while(i < (*tope) && !encontre){
		if(vector_desordenado[i]== elimino){
			encontre=true;
		}
		i++;
	}
	vector_desordenado[i-1]= vector_desordenado[(*tope)-1];
	(*tope)--;

}





int main(){
	int vector_ordenado[MAX_ORDENADO]={0,1,5,7,12};
	int vector_desordenado[MAX_DESORDENADO]={1,9,7,2,5,0,8};
	int tope_ordenado=5;
	int tope_desordenado=7;
	int inserto_paquete=9;
	int elimino_paquete=5;
	int inserta_record=9;
	int elimina_record=0;
	for (int i = 0; i < tope_ordenado; ++i){
		printf("%i,", vector_ordenado[i] );
	}
	printf("\n");
	for (int i = 0; i < tope_desordenado; ++i){
		printf("%i,", vector_desordenado[i] );
	}
	printf("\n");
	insertar_ordenado(vector_ordenado,&tope_ordenado, inserto_paquete);
	insertar_desordenado(vector_desordenado,&tope_desordenado, inserta_record);
	for (int i = 0; i < tope_desordenado; ++i){
		printf("%i,", vector_desordenado[i] );
	}
	printf("\n");
	eliminar_ordenado(vector_ordenado,&tope_ordenado, elimino_paquete);
	eliminar_desordenado(vector_desordenado,&tope_desordenado, elimina_record);
	for (int i = 0; i < tope_ordenado; ++i){
		printf("%i,", vector_ordenado[i] );
	}
	printf("\n");
	for (int i = 0; i < tope_desordenado; ++i){
		printf("%i,", vector_desordenado[i]);
	}
	printf("\n");
}
