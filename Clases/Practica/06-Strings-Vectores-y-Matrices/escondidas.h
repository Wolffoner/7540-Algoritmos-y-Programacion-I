#ifndef __ESCONDIDAS_H__
#define __ESCONDIDAS_H__

#define MAX_COLABS 23
#define MAX_NOMBRE 50

typedef struct colaborador{
	char nombre[MAX_NOMBRE];
	int fil;
	int col;
}colaborador_t;

//PRE
//POST
void imprimir_posicion(colaborador_t colabs[MAX_COLABS], int cantidad_colabs, char nombre_buscado[MAX_NOMBRE]);


//PRE
//POST
void cargar_vector(colaborador_t colabs[MAX_COLABS], int* cantidad_colabs);


#endif /*__ESCONDIDAS_H*/