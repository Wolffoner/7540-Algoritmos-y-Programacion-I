#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct colab {
	char nombre[MAX_NOMBRE];
	int goles_metidos;
	int goles_errados;
	int faltas_cometidas;
	int cantidad_lesiones;
} colab_t;

// ACA ASUMIMOS QUE PUEDE HABER COLABORADORES NUEVOS!!
/*
int main(){
	
	FILE* colabs = fopen("colabs.dat", "r");
	// --> Chequear si se abrio bien!!
	FILE* actualizaciones = fopen("actualizaciones.dat", "r");
	// --> Chequear si se abrio bien!!
	FILE* colabs_nuevo = fopen("colabs_nuevo.dat", "w");
	// --> Chequear si se abrio bien!!

	colab_t colab;
	colab_t actualizacion;

	size_t leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	size_t leidos_actu = fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);

	while(leidos_colabs == 1 && leidos_actu == 1){

		int cmp = strcmp(colab.nombre, actualizacion.nombre);
		if (cmp < 0) {
			fwrite(&colab, sizeof(colab_t), 1, colabs_nuevo);
			leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
		} else if (cmp > 0) {
			fwrite(&actualizacion, sizeof(colab_t), 1, colabs_nuevo);
			leidos_actu = fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);
		} else {
			colab.goles_errados += actualizacion.goles_errados;
			colab.goles_metidos += actualizacion.goles_metidos;
			colab.faltas_cometidas += actualizacion.faltas_cometidas;
			colab.cantidad_lesiones += actualizacion.cantidad_lesiones;
			fwrite(&colab, sizeof(colab_t), 1, colabs_nuevo);
			leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
			leidos_actu = fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);
		}
	}

	while(leidos_colabs == 1){
		fwrite(&colab, sizeof(colab_t), 1, colabs_nuevo);
		leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	}

	while(leidos_actu == 1){
		fwrite(&actualizacion, sizeof(colab_t), 1, colabs_nuevo);
		leidos_actu = fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);
	}


	fclose(colabs);
	fclose(actualizaciones);
	fclose(colabs_nuevo);
	// rename(...);

	return 0;
}
*/

// ACA ASUMIMOS QUE PUEDE NO PUEDE HABER COLABORADORES NUEVOS!!
int main(){
	
	FILE* colabs = fopen("colabs.dat", "r+");
	// --> Chequear si se abrio bien!!
	FILE* actualizaciones = fopen("actualizaciones.dat", "r");
	// --> Chequear si se abrio bien!!

	colab_t colab;
	colab_t actualizacion;

	
	size_t leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);
	printf("\n SIN ACTUALIZAR \n");
	while (leidos_colabs == 1){
		printf("%s - %i - %i - %i - %i\n", colab.nombre, colab.goles_metidos, colab.goles_errados, colab.faltas_cometidas, colab.cantidad_lesiones);
		if (strcmp(colab.nombre, actualizacion.nombre) == 0) {
			colab.goles_errados += actualizacion.goles_errados;
			colab.goles_metidos += actualizacion.goles_metidos;
			colab.faltas_cometidas += actualizacion.faltas_cometidas;
			colab.cantidad_lesiones += actualizacion.cantidad_lesiones;
			fseek(colabs, (-1) * (int)sizeof(colab_t), SEEK_CUR);
			fwrite(&colab, sizeof(colab_t), 1, colabs);
			fread(&actualizacion, sizeof(colab_t), 1, actualizaciones);
		}
		leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	}
	printf("\n ACTUALIZADO \n");
		
	fclose(colabs);
	fclose(actualizaciones);

	colabs = fopen("colabs.dat", "r");
	leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	
	while (leidos_colabs == 1){
		printf("%s - %i - %i - %i - %i\n", colab.nombre, colab.goles_metidos, colab.goles_errados, colab.faltas_cometidas, colab.cantidad_lesiones);
		leidos_colabs = fread(&colab, sizeof(colab_t), 1, colabs);
	}

	fclose(colabs);


	return 0;
}
