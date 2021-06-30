//Parcial 18-06-2020
//EJERCICIO 1 - VARIANTE 3

typedef struct elfo {
	char nombre[MAX_NOMBRE];
	int edad;
	int altura;
	int numero_calzado;
	char estado_bolsa;
	char color_bolsa;
} elfo_t;

typedef struct casa {
	char direccion[MAX_DIRECCION];
	elfo_t elfos[MAX_ELFOS];
	int cant_elfos;
} casa_t;

const char NUEVO = 'N'; 

void actualizar_bolsas_por_casa(casa_t casas[MAX_CASAS], int tope_casas, int bolsas_por_casa[MAX_CASAS]){
	
	for (int casa_actual = 0; casa_actual < tope_casas; casa_actual++){
		bolsas_por_casa[casa_actual] = 0;
		for (int elfo_actual = 0; elfo_actual < casas[casa_actual].cant_elfos; elfo_actual++){
			if (casas[casa_actual].elfos[elfo_actual].estado_bolsa != NUEVO){
				bolsas_por_casa[casa_actual]++;
			}
		}
	}
}


//EJERCICIO 2 - VARIANTE 3

typedef struct mago {
	bool hay_alguien;
	char nombre[MAX_NOMBRE];
	char vota_a; // Gandalf - Saruman - Indeciso
	int nivel; // del 1 al 5
} mago_t;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;
const char GANDALF = 'G';

int fila_con_mayor_votos(mago_t butacas[MAX_FILAS][MAX_COLUMNAS]){
	int fila_max = -1;
	int votos_fila_max = -1;

	for(int fil = 0; fil < MAX_FILAS; fil++){
		int votos_fila_actual = 0;
		for(int col = 0; col < MAX_COLUMNAS; col++){
			if(butacas[fil][col].hay_alguien){
				if(butacas[fil][col].voto_a == GANDALF){
					votos_fila_actual++;
				}
			}
		}
		if(votos_fila_actual > votos_fila_max){
			fila_max = fil;
			votos_fila_max = votos_fila_actual;
		}
	}

	return fila_max;
}


//Parcial 10-12-2020
//EJERCICIO 4 - VARIANTE 1

typedef struct clavo {
	int largo;
	int dobladez;
	bool oxidado;
} clavo_t;

void mostrar_clavo_ganador(clavo_t vec_ed[], int tope_ed, clavo_t vec_edd[], int tope_edd, clavo_t vec_eddy[], int tope_eddy){
	int pos_clavo_largo_ed = -1;
	int lon_clavo_largo = -1;

	for(int i = 0; i < tope_ed; i++){
		if(i % 2 == 0){
			if(vec_ed[i].largo > lon_clavo_largo){
				pos_clavo_largo_ed = i;
				lon_clavo_largo = vec_ed[i].largo;
			}
		}
	}
	

	int pos_clavo_largo_edd = -1;
	lon_clavo_largo = -1;

	for(int i = 0; i < tope_edd; i++){
		if(i % 2 != 0){
			if(vec_edd[i].largo > lon_clavo_largo){
				pos_clavo_largo_edd = i;
				lon_clavo_largo = vec_edd[i].largo;
			}	
		}
	}


	int pos_clavo_largo_eddy = -1;
	lon_clavo_largo = -1;

	for(int i = 0; i < tope_eddy; i++){
		if(vec_eddy[i].largo > lon_clavo_largo){
			pos_clavo_largo_eddy = i;
			lon_clavo_largo = vec_eddy[i].largo;
		}
	}


	int dobladez_ed = vec_ed[pos_clavo_largo_ed].dobladez;
	int dobladez_edd = vec_edd[pos_clavo_largo_edd].dobladez;
	int dobladez_eddy = vec_eddy[pos_clavo_largo_eddy].dobladez;

	if (dobladez_ed < dobladez_edd && dobladez_ed < dobladez_eddy){
		printf("Ganó Ed y su clavo está en la posicion %i\n", pos_clavo_largo_ed);
	} else if (dobladez_edd < dobladez_ed && dobladez_edd < dobladez_eddy) {
		printf("Ganó Edd y su clavo está en la posicion %i\n", pos_clavo_largo_edd);
	} else {
		printf("Ganó Eddy y su clavo está en la posicion %i\n", pos_clavo_largo_eddy);		
	}
}